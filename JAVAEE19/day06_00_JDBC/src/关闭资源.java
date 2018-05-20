import static org.junit.Assert.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class �ر���Դ {
	public static void main(String[] args) {
		Connection conn = null;
		Statement statement = null;
		ResultSet res = null;
		try {
			// 1.��������
			Class.forName("com.mysql.jdbc.Driver");
			// 2.��ȡ����Connection
			Properties info = new Properties();
			conn = DriverManager
					.getConnection("jdbc:mysql://127.0.0.1:3306/dong?user=root&password=dong");

			// 3.���sql���ִ�ж��� Statement
			statement = conn.createStatement();

			// 4.ִ��sql��䣬�����ؽ��
			res = statement
					.executeQuery("SELECT * FROM day06 ORDER BY id DESC");

			// 5.������
			while (res.next()) {
				System.out.println("ѧ��:" + res.getObject(1));
				System.out.println("����:" + res.getObject(2));
				System.out.println("����:" + res.getObject(3));
				System.out.println("ע��ʱ��:" + res.getObject(4));
				System.out.println("--------------------------------------");
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			// 6.�ر���Դ
			if (res != null) {
				try {
					res.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			if (statement != null) {
				try {
					statement.close();
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
}
