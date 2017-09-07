<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>绿农优品</title>
</head>
<style type="text/css">
	.clear{
		clear:both;
	}
	h1{
		margin: 25px 20%;
	}
	span{
		font-size: 30px;
	}
	.two{
		padding: 0px 60px 0px 0px;
	}
	.three{
		padding: 0px 24px 0px 0px;
	}
	body{
		background-image: url("images/2.jpg");
		background-repeat: no-repeat;
		background-color: #629BD0;
	}
	#reg{
		margin: 20px 0px 0px 15px;
		width: 300px;
		height: 30px;
		color: #B79184;
		background-color: green;
		border-color: black;
	}
	#form{
		float: right;
		height: 520px;
		width: 520px;
		background-color: #77A7D5;
	}
	#inside{
		height: 450px;
		width: 470px;
		margin: 10px 24px;
		background-color: #81AED7;
	}
	#logo{
		float: right;
		font-size: 20px;
		font-family: "microsoft yahei";
	}
</style>
<body text = "red">
	<form action="${pageContext.request.contextPath }/servlet/RegServlet"
		method="post" id="form">
		<div id=inside>
			<h1>用户注册</h1>
			<div class="clear"></div>
			<span class="three">用户名：</span>
			<input type="text" name="username" value="${uf.username }">${uf.msg.username }${error }<br><br>
			<span class="two">密码：</span><input type="password" name="password" value="${uf.password }">${uf.msg.password }<br> <br>
			<span >确认密码：</span><input type="password" name="repassword" value="${uf.repassword }">${uf.msg.repassword }<br> <br>
			<span class="two">邮箱：</span><input type="text" name="email" value="${uf.email }">${uf.msg.email }<br> <br>
			<span class="two">生日：</span><input	type="text" name="birthday" value="${uf.birthday }">
			
			<c:if test="${empty uf.msg.birthday }">
			<font size="4">例：1996-2-22</font>
			</c:if>
			${uf.msg.birthday }<br><br>
			<input	type="submit" value="注册" id="reg">
		</div>
		<div id="logo">帅东</div>
	</form>
</body>
</html>