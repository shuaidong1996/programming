import static org.junit.Assert.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

import org.junit.Test;

//�������ݿ�����ַ�ʽ

public class �������ݿ�2 {
	@Test
	public void test1() throws SQLException, ClassNotFoundException {
		//1.��������
		Class.forName("com.mysql.jdbc.Driver");
		
		//2.��ȡ����Connection
		Properties info = new Properties();
		info.setProperty("user", "root");
		info.setProperty("password", "dong");
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong",info);
		
		
		//3.���sql���ִ�ж���  Statement
		Statement statement = conn.createStatement();
		
		//4.ִ��sql��䣬�����ؽ��
		ResultSet res = statement.executeQuery("SELECT * FROM day06 ORDER BY id DESC");
		
		//5.������
		while(res.next()){
			System.out.println("ѧ��:"+res.getObject(1));
			System.out.println("����:"+res.getObject(2));
			System.out.println("����:"+res.getObject(3));
			System.out.println("ע��ʱ��:"+res.getObject(4));
			System.out.println("--------------------------------------");
		}
		
		//6.�ر���Դ
		res.close();
		statement.close();
		conn.close();
	}
	@Test
	public void test2() throws SQLException, ClassNotFoundException {
		//1.��������
		Class.forName("com.mysql.jdbc.Driver");
		
		//2.��ȡ����Connection
		Properties info = new Properties();
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong?user=root&password=dong");
		
		
		//3.���sql���ִ�ж���  Statement
		Statement statement = conn.createStatement();
		
		//4.ִ��sql��䣬�����ؽ��
		ResultSet res = statement.executeQuery("SELECT * FROM day06 ORDER BY id DESC");
		
		//5.������
		while(res.next()){
			System.out.println("ѧ��:"+res.getObject(1));
			System.out.println("����:"+res.getObject(2));
			System.out.println("����:"+res.getObject(3));
			System.out.println("ע��ʱ��:"+res.getObject(4));
			System.out.println("--------------------------------------");
		}
		
		//6.�ر���Դ
		res.close();
		statement.close();
		conn.close();
	}
}
