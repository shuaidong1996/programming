import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import com.mysql.jdbc.Driver;

public class �������ݿ� {
	public static void main(String[] args) throws SQLException {
		//1.ע��������������ʹ�ã�
		DriverManager.registerDriver(new com.mysql.jdbc.Driver());
		
		/*����1.����Driver���ʱ�򣬻�ִ��java.sql.DriverManager.registerDriver(new Driver());
		 * 		�ᵼ��ע�����Σ���ʵ�����룬��һ�����ǲ�ע�᲻�͵��� ��ֱ��new com.mysql.jdbc.Driver(); �Ҳ���Ҳ�ǿ��Ե�
		 *   2.ǿ���������ݿ�����.jar
		*/
		
		//2.��ȡ����Connection
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong","root","dong");//ǰ����Э��+��Э��+ip+�˿�+���ݿ���
		
		//3.���sql���ִ�ж���  Statement
		Statement statement = conn.createStatement();
		
		//4.ִ��sql��䣬�����ؽ��
		ResultSet res = statement.executeQuery("SELECT * FROM day06 ORDER BY id DESC");
		
		//5.������
		while(res.next()){
			//���ֻ�ȡֵ�÷���  һ���� ���֣�һ�������������ʹ������
			System.out.println("ѧ��:"+res.getObject(1));
			System.out.println("����:"+res.getObject("name"));
			System.out.println("����:"+res.getObject(3));
			System.out.println("ע��ʱ��:"+res.getObject("time"));
			System.out.println("--------------------------------------");
		}
		
		//6.�ر���Դ
		res.close();
		statement.close();
		conn.close();
	}

}
