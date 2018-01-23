package com.dong.dbutils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ResourceBundle;

public class DbUtils {
	private static String driverClass;
	private static String url;
	private static String username;
	private static String password;
	
	static{
		//����properties�ļ�
		ResourceBundle bundle = ResourceBundle.getBundle("dbinfo");
		driverClass = bundle.getString("driverClass");
		url = bundle.getString("url");
		username = bundle.getString("username");
		password = bundle.getString("password");
		//�ھ�̬����ֱ��ע������
		try {
			Class.forName(driverClass);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static Connection getConnection() throws SQLException{
		return DriverManager.getConnection(url,username,password);
	}
	//�ر���Դ�ķ���
	public static void closeAll(ResultSet rs,Statement state,Connection conn){
		//�رյ�ʱ���ж��Ƿ�Ϊ��
		if (rs != null) {
			try {
				rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		if (state != null) {
			try {
				state.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
		if (conn != null) {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();
			}
		}
	}
}
