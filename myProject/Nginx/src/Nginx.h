#ifndef NGINX_H
#define NGINX_H
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <errno.h> 
#include <sys/socket.h>
#include <assert.h>
#include <signal.h>
#include <netinet/tcp.h> 
#include <map>
#include <string>

using namespace std;

class DtbtNginx;
/* 每个客户端都分配一个Nginx */
class Nginx
{
public:
	/* 全局的DtbtNginx指针 */
	DtbtNginx *dbNginx;
	Nginx *nginxs;//因为需要给其他节点发送消息，所以得保存起始地址
	int epollfd;//因为有些数据可能写不完 有些数据发不完 需要继续监听 所以需要这个变量
	/* 关于epoll的数据 */
	int events;//epoll的模式 et lt 等
	int eStatus;//0:还未加入epoll 1:已经加入epoll----避免重复添加到epoll
	int keepAliveInterval;//心跳的间隔时间 秒
	int ActiveInterval;//断开时间
	long lastKeepAlive;//上次心跳的时间(秒) 从1970年1月1日开始
	long lastActive;//上次活跃的时间(秒) 从1970年1月1日开始
	/* 内部的数据 */
	char *readBuf;//读到的数据
	int readIdx;//读到的位置（可能一次读不全）
	int readBufSize;//buf大小
	char *writeBuf;//写的数据--避免没有写完
	int writeIdx;
	int writeLen;
	int writeBufSize;
	string clientName;//ip prot
	int sockfd;//发送或者接收的套接字
	typedef void(Nginx::*func)(char *proto);
	map<int, func> callBack;//回调函数
public:
	Nginx(int readBufSize = 1024);
	~Nginx();
	bool Read();
	bool ReadWithoutCmd();
	bool Write();
	bool WriteProto(int cmd, string data);
	void SetReadBuf(int size);
	/* 收到proto的回调函数 */
	void VoteRcve(char *proto);
	void AckVote2LeaderRcve(char *proto);//响应投票1
	void AckVote2FollowerRcve(char *proto);//响应投票2
	void SynchDataRcve(char *proto);//同步数据
	void AckData2LeaderRcve(char *proto);//响应同步数据
	void AckData2FollowerRcve(char *proto);//再响应同步数据
	void KeepAliveRcve(char *proto);
	/* 主动发送proto的函数 */
	void AckVote2LeaderSend(string proto);//响应投票
	void AckData2LeaderSend(string proto);//响应数据同步

	/* 关于epoll */
	int SetNoBlocking(int fd);
	void Addfd2Read();
	void Addfd2Write();
	void Removefd();

	void CloseSocket(int sockfd);
};
#endif