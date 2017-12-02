﻿#include "http_conn.h"

const char* ok_200_title = "OK";
const char* error_301_title = "Found Other";
const char* error_400_title = "Bad Request";
const char* error_400_form = "Your request has bad syntax or is inherently impossible to satisfy.\n";
const char* error_403_title = "Forbidden";
const char* error_403_form = "You do not have permission to get file from this server.\n";
const char* error_404_title = "Not Found";
const char* error_404_form = "The requested file was not found on this server.\n";
const char* error_500_title = "Internal Error";
const char* error_500_form = "There was an unusual problem serving the requested file.\n";
const char* doc_root = "/var/www/html/";

int setnonblocking( int fd )
{
    int old_option = fcntl( fd, F_GETFL );
    int new_option = old_option | O_NONBLOCK;
    fcntl( fd, F_SETFL, new_option );
    return old_option;
}

void addfd( int epollfd, int fd, bool one_shot )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLRDHUP;
    if( one_shot )
    {
       event.events |= EPOLLONESHOT;
    }
    epoll_ctl( epollfd, EPOLL_CTL_ADD, fd, &event );
    setnonblocking( fd );
}

void removefd( int epollfd, int fd )
{
    epoll_ctl( epollfd, EPOLL_CTL_DEL, fd, 0 );
    if(close( fd ))
	{
		printf("close error:%s\n",strerror(errno));
	}
}

void modfd( int epollfd, int fd, int ev )
{
    epoll_event event;
    event.data.fd = fd;
    event.events = ev | EPOLLET | EPOLLONESHOT | EPOLLRDHUP;
    epoll_ctl( epollfd, EPOLL_CTL_MOD, fd, &event );
}

int http_conn::m_user_count = 0;
int http_conn::m_epollfd = -1;

void http_conn::close_conn()
{
    if( m_sockfd != -1 )
    {
        removefd( m_epollfd, m_sockfd );
        m_sockfd = -1;
        m_user_count--;
    }
}

void http_conn::init( int sockfd, const sockaddr_in& addr )
{
    m_sockfd = sockfd;
    m_address = addr;
    int error = 0;
    socklen_t len = sizeof( error );
    getsockopt( m_sockfd, SOL_SOCKET, SO_ERROR, &error, &len );//SO_ERROR获取错误状态并清除
    int reuse = 1;
    setsockopt( m_sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof( reuse ) );
    addfd( m_epollfd, sockfd, true );//初始化就监听读事件
    m_user_count++;

    init();
}

void http_conn::init()
{
    m_check_state = CHECK_STATE_REQUESTLINE;
    m_linger = false;

    m_method = GET;
    m_url = 0;
    m_version = 0;
    m_content_length = 0;
    m_host = 0;
    m_start_line = 0;
    m_checked_idx = 0;
    m_read_idx = 0;
    m_write_idx = 0;
    memset( m_read_buf, '\0', READ_BUFFER_SIZE );
    memset( m_write_buf, '\0', WRITE_BUFFER_SIZE );
    memset( m_real_file, '\0', FILENAME_LEN );
}
/*解析是否有\r\n行*/
http_conn::LINE_STATUS http_conn::parse_line()
{
    char temp;
    for ( ; m_checked_idx < m_read_idx; ++m_checked_idx )
    {
        temp = m_read_buf[ m_checked_idx ];
        if ( temp == '\r' )
        {
            if ( ( m_checked_idx + 1 ) == m_read_idx )
            {
                return LINE_OPEN;//数据不完整（有可能下一次读取能读到一个'\n'）
            }
			/*如果是以 \r\n 结尾说明读到了完整行*/
            else if ( m_read_buf[ m_checked_idx + 1 ] == '\n' )
            {
                m_read_buf[ m_checked_idx++ ] = '\0';
                m_read_buf[ m_checked_idx++ ] = '\0';
                return LINE_OK;
            }
			/*除此之外都是行出错*/
            return LINE_BAD;
        }
		/*正如上面那样，有可能这一次读到的就是'\n'*/
        else if( temp == '\n' )
        {
            if( ( m_checked_idx > 1 ) && ( m_read_buf[ m_checked_idx - 1 ] == '\r' ) )
            {
                m_read_buf[ m_checked_idx-1 ] = '\0';
                m_read_buf[ m_checked_idx++ ] = '\0';
                return LINE_OK;
            }
            return LINE_BAD;
        }
    }
	/*如果解析到现在还没有\r\n 说明数据还不完整*/
    return LINE_OPEN;
}
/*读取socket里面的数据到内存中*/
bool http_conn::http_read()
{
    if( m_read_idx >= READ_BUFFER_SIZE )
    {
        return false;
    }

    int bytes_read = 0;
    while( true )
    {
        bytes_read = recv( m_sockfd, m_read_buf + m_read_idx, READ_BUFFER_SIZE - m_read_idx, 0 );
		//printf("接收到 %d\n",bytes_read);
        if ( bytes_read == -1 )
        {
            if( errno == EAGAIN || errno == EWOULDBLOCK )
            {
                break;
            }
            return false;
        }
        else if ( bytes_read == 0 )
        {
            return false;
        }

        m_read_idx += bytes_read;
    }
    return true;
}
/*解析请求消息行*/
http_conn::HTTP_CODE http_conn::parse_request_line( char* text )
{
    m_url = strpbrk( text, " \t" );
    if ( ! m_url )
    {
        return BAD_REQUEST;
    }
    char* method = text;
    if ( strcasecmp( method, "GET" ) == 0 )//只支持get请求
    {
        m_method = GET;
    }
    else
    {
		//测试用--把post请求打印日志
		// FILE *fp = fopen("log/postRequest.text","w+");  
		// fwrite(text, 1024, 1, fp);  
        // fclose(fp);
        return BAD_REQUEST;
    }
	*m_url++ = '\0';
    m_url += strspn( m_url, " \t" );
    m_version = strpbrk( m_url, " \t" );
    if ( ! m_version )
    {
        return BAD_REQUEST;
    }
    *m_version++ = '\0';
    m_version += strspn( m_version, " \t" );
    if ( strcasecmp( m_version, "HTTP/1.1" ) != 0 && strcasecmp( m_version, "HTTP/1.0" ) != 0)
    {
        return BAD_REQUEST;
    }

    if ( strncasecmp( m_url, "http://", 7 ) == 0 )
    {
        m_url += 7;
        m_url = strchr( m_url, '/' );
    }

    if ( ! m_url || m_url[ 0 ] != '/' )
    {
        return BAD_REQUEST;
    }
	++m_url;//这样可以去掉/
	//判断需不需要重定位--因为文件的传输不用当前服务器
	//if(strstr(m_url, ".exe") || strstr(m_url, ".pdf"))
	
    m_check_state = CHECK_STATE_HEADER;
    return NO_REQUEST;
}
/*解析头部*/
http_conn::HTTP_CODE http_conn::parse_headers( char* text )
{
    if( text[ 0 ] == '\0' )
    {
        if ( m_method == HEAD )
        {
            return GET_REQUEST;
        }

        if ( m_content_length != 0 )
        {
            m_check_state = CHECK_STATE_CONTENT;
            return NO_REQUEST;
        }

        return GET_REQUEST;
    }
    else if ( strncasecmp( text, "Connection:", 11 ) == 0 )
    {
        text += 11;
        text += strspn( text, " \t" );
        if ( strcasecmp( text, "keep-alive" ) == 0 )
        {
            m_linger = true;
        }
    }
    else if ( strncasecmp( text, "Content-Length:", 15 ) == 0 )
    {
        text += 15;
        text += strspn( text, " \t" );
        m_content_length = atol( text );
    }
    else if ( strncasecmp( text, "Host:", 5 ) == 0 )
    {
        text += 5;
        text += strspn( text, " \t" );
        m_host = text;
    }
    else
    {
        //printf( "未识别的行： %s\n", text );
    }

    return NO_REQUEST;//请求不完整
}
/*解析内容*/
http_conn::HTTP_CODE http_conn::parse_content( char* text )
{
	/*已经读到数据 >= 请求消息体长度 + 已经解析的长度 (消息体是不需要解析的)*/
    if ( m_read_idx >= ( m_content_length + m_checked_idx ) )
    {
        text[ m_content_length ] = '\0';
        return GET_REQUEST;
    }
	/*数据不完整还需要读*/
    return NO_REQUEST;
}
/*对整个请求进行解析*/
http_conn::HTTP_CODE http_conn::process_read()
{
    LINE_STATUS line_status = LINE_OK;//读取状态
    HTTP_CODE ret = NO_REQUEST;		//占时请求状态设置为不完整
    char* text = 0;

	/*下面就是限状态机编程方法*/
    while ( ( ( m_check_state == CHECK_STATE_CONTENT ) && ( line_status == LINE_OK  ) )//主状态机：正在分析请求内容。从状态机：读到完整行
                || ( ( line_status = parse_line() ) == LINE_OK ) )//从状态机读到\r\n
    {
        text = get_line();
        m_start_line = m_checked_idx;
        //printf( "解析了一行: %s\n", text );

        switch ( m_check_state )
        {
			/*解析请求消息行*/
            case CHECK_STATE_REQUESTLINE:
            {
                ret = parse_request_line( text );
                if ( ret == BAD_REQUEST )
                {
                    return BAD_REQUEST;
                }
                break;
            }
			/*解析请求消息头*/
            case CHECK_STATE_HEADER:
            {
                ret = parse_headers( text );
                if ( ret == BAD_REQUEST )
                {
                    return BAD_REQUEST;
                }
                else if ( ret == GET_REQUEST )
                {
                    return do_request();
                }
                break;
            }
			/*解析请求消息体*/
            case CHECK_STATE_CONTENT:
            {
                ret = parse_content( text );
                if ( ret == GET_REQUEST )
                {
                    return do_request();
                }
                line_status = LINE_OPEN;
                break;
            }
            default:
            {
                return INTERNAL_ERROR;
            }
        }
    }
    return NO_REQUEST;
}
/*获取文件*/
http_conn::HTTP_CODE http_conn::do_request()
{
    strcpy( m_real_file, doc_root );
    int len = strlen( doc_root );
    strncpy( m_real_file + len, m_url, FILENAME_LEN - len - 1 );//这里应该可以优化 strlen(m_url) + 1
    if ( stat( m_real_file, &m_file_stat ) < 0 )//提供文件名字，获取文件对应属性。
    {
        return NO_RESOURCE;//没有资源
    }

    if ( ! ( m_file_stat.st_mode & S_IROTH ) )//文件对应的模式，文件，目录    S_IROTH  其他用户具可读取权限
    {
        return FORBIDDEN_REQUEST;//客户端对资源没有足够的访问权限
    }

    if ( S_ISDIR( m_file_stat.st_mode ) )//是否为目录
    {
        return BAD_REQUEST;
    }

    int fd = open( m_real_file, O_RDONLY );
	int fileSize = m_file_stat.st_size;
    m_file_address = ( char* )mmap( 0, fileSize, PROT_READ, MAP_PRIVATE, fd, 0 );//PROT_READ 页内容可以被读取
	//printf("请求的文件大小：%d\n",fileSize);
    close( fd );
    return FILE_REQUEST;
}

void http_conn::unmap()
{
    if( m_file_address )
    {
        munmap( m_file_address, m_file_stat.st_size );
        m_file_address = 0;
    }
}

bool http_conn::http_write()
{
    int temp = 0;
    if ( m_write_idx == 0 )
    {
        modfd( m_epollfd, m_sockfd, EPOLLIN );
        init();
        return true;
    }
	//printf("文件名：%s\n",m_url);
	//printf("内容：%s\n",m_write_buf);
	/*写入响应消息*/
	while( bytes_have_response < m_write_idx )
	{
		temp = write( m_sockfd, m_write_buf + bytes_have_response, m_write_idx - bytes_have_response);
		if(temp > 0)
			bytes_have_response += temp;
		//printf("response这次发送了：%d\t 一共发送了：%d\n",temp,bytes_have_response);
		//printf("向%d 发送了%d\n",m_sockfd,temp);
		if ( temp <= -1 )
		{
			if( errno == EAGAIN )
			{
				printf("当前不可写，继续监听写事件\n");
				modfd( m_epollfd, m_sockfd, EPOLLOUT );
				return true;
			}
			printf("response发送失败\n");
			bytes_have_response = 0;
			unmap();
			return false;
		}
	}
	
	/*如果有文件写入文件*/
	if(m_file_address != NULL)
	{
		int fileSize = m_file_stat.st_size;
		while(bytes_have_file < fileSize)
		{
			 temp = write( m_sockfd, m_file_address + bytes_have_file, fileSize - bytes_have_file);
			 if(temp > 0)
				bytes_have_file += temp;
			 //printf("file这次发送了：%d\t 一共发送了：%d\n",temp,bytes_have_file);
			 if ( temp <= -1 )
			 {
				 if( errno == EAGAIN )
				 {
					 printf("当前不可写，继续监听写事件\n");
					 modfd( m_epollfd, m_sockfd, EPOLLOUT );
					 return true;
				 }
				 printf("file发送失败\n");
				 unmap();
				 return false;
			}
		}
	}
	/*删除 和 初始化*/
	unmap();
	bytes_have_response = 0;
	bytes_have_file = 0;
	
	if( m_linger )
	{
		//printf("发送完毕，keep-alive继续监听socket:%d\n",m_sockfd);
		init();
		modfd( m_epollfd, m_sockfd, EPOLLIN );
		return true;
	}
	else
	{
		//printf("发送完毕，close不再监听socket:%d\n",m_sockfd);
		close_conn();
		return false;
	} 
}
////////////////////////////////////////////////////////////////////
bool http_conn::add_response( const char* format, ... )
{
    if( m_write_idx >= WRITE_BUFFER_SIZE )
    {
        return false;
    }
    va_list arg_list;
    va_start( arg_list, format );
    int len = vsnprintf( m_write_buf + m_write_idx, WRITE_BUFFER_SIZE - 1 - m_write_idx, format, arg_list );
    if( len >= ( WRITE_BUFFER_SIZE - 1 - m_write_idx ) )
    {
        return false;
    }
    m_write_idx += len;
    va_end( arg_list );
    return true;
}
//////////////////////添加请求消息行/////////////////////////////
bool http_conn::add_status_line( int status, const char* title )
{
    return add_response( "%s %d %s\r\n", "HTTP/1.1", status, title );
}
//////////////////////添加请求消息头/////////////////////////////
bool http_conn::add_headers( int content_len, const char *location)
{
    add_content_length( content_len );
    add_linger();
	//支持重定向技术
	if(location)
		add_Location(location);
    add_blank_line();
}
//内容长度
bool http_conn::add_content_length( int content_len )
{
    return add_response( "Content-Length: %d\r\n", content_len );
}
//keep-alive
bool http_conn::add_linger()
{
    return add_response( "Connection: %s\r\n", ( m_linger == true ) ? "keep-alive" : "close" );
}
//重定向
bool http_conn::add_Location(const char *otherUrl)
{
	return add_response( "Location: %s\r\n", otherUrl );
}
//////////////////////添加空行/////////////////////////////
bool http_conn::add_blank_line()
{
    return add_response( "%s", "\r\n" );
}
//////////////////添加请求正文(用于错误响应)////////////////
bool http_conn::add_content( const char* content )
{
    return add_response( "%s", content );
}
//写响应 行 头 体
bool http_conn::process_write( HTTP_CODE ret )
{
	// add_status_line( 302, error_301_title );
    // add_headers( strlen( error_301_title ) );
	// add_content( error_301_form );
	// return true;
    switch ( ret )
    {
        case INTERNAL_ERROR:
        {
            add_status_line( 500, error_500_title );
            add_headers( strlen( error_500_form ) );
            if ( ! add_content( error_500_form ) )
            {
                return false;
            }
            break;
        }
        case BAD_REQUEST:
        {
            add_status_line( 400, error_400_title );
            add_headers( strlen( error_400_form ) );
            if ( ! add_content( error_400_form ) )
            {
                return false;
            }
            break;
        }
        case NO_RESOURCE:
        {
            add_status_line( 404, error_404_title );
            add_headers( strlen( error_404_form ) );
            if ( ! add_content( error_404_form ) )
            {
                return false;
            }
            break;
        }
        case FORBIDDEN_REQUEST:
        {
            add_status_line( 403, error_403_title );
            add_headers( strlen( error_403_form ) );
            if ( ! add_content( error_403_form ) )
            {
                return false;
            }
            break;
        }
        case FILE_REQUEST:
        {
            add_status_line( 200, ok_200_title );
            if ( m_file_stat.st_size != 0 )
            {
                add_headers( m_file_stat.st_size );
                return true;
            }
            else
            {
                const char* ok_string = "<html><body></body></html>";
                add_headers( strlen( ok_string ) );
                if ( ! add_content( ok_string ) )
                {
                    return false;
                }
            }
        }
        default:
        {
            return false;
        }
    }
    return true;
}

void http_conn::process()
{
    HTTP_CODE read_ret = process_read();//读请求
    if ( read_ret == NO_REQUEST )
    {
		/*请求不完整，继续监听，现在不做任何处理*/
		printf("请求不完整\n");
        modfd( m_epollfd, m_sockfd, EPOLLIN );
        return;
    }
	
	/*准备写入的内容*/
    bool write_ret = process_write( read_ret );//写响应头部
    if ( ! write_ret )
    {
        close_conn();
    }
	/*监听写事件★★★需要写给客户端*/
    modfd( m_epollfd, m_sockfd, EPOLLOUT );//写入http或者二进制文件
}

