import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.junit.Test;

import com.dong.entity.dbUser;


public class CRUD {
	
	@Test
	public void testInsert() throws Exception{
		Class.forName("com.mysql.jdbc.Driver");
		
		//assign ����
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong","root","dong");
		
		Statement state = conn.createStatement();
		
		int res = state.executeUpdate("INSERT INTO day06(`name`,`score`) VALUES('����ӱ',77)");
		if(res>0){
			System.out.println("�ɹ��޸���"+res+"��");
		}else{
			System.out.println("�޸���"+res+"��");
		}
	}
	@Test
	public void testDelete() throws Exception{
		Class.forName("com.mysql.jdbc.Driver");
		
		//assign ����
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong","root","dong");
		
		Statement state = conn.createStatement();
		
		int res = state.executeUpdate("DELETE FROM day06 WHERE name='����ӱ'");
		if(res>0){
			System.out.println("�ɹ��޸���"+res+"��");
		}else{
			System.out.println("�޸���"+res+"��");
		}
	}
	@Test
	public void testUpdate() throws Exception{
		Class.forName("com.mysql.jdbc.Driver");
		
		//assign ����
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong","root","dong");
		
		Statement state = conn.createStatement();
		
		int res = state.executeUpdate("UPDATE day06 SET NAME='����',score='11' WHERE id=1002");
		if(res>0){
			System.out.println("�ɹ��޸���"+res+"��");
		}else{
			System.out.println("�޸���"+res+"��");
		}
	}
	@Test
	public void testSelect() throws Exception{
		Class.forName("com.mysql.jdbc.Driver");
		
		//assign ����
		Connection conn = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/dong","root","dong");
		
		Statement state = conn.createStatement();
		
		ResultSet res = state.executeQuery("select * from day06");
		List<dbUser> list = new ArrayList<dbUser>();
		while(res.next()){
			dbUser u = new dbUser();
			//�������ַ�ʽ�����Ի�ȡֵ
			/*u.setId(res.getInt("id"));
			u.setName(res.getString("name"));
			u.setScore(res.getInt("score"));
			u.setTime(res.getDate("time"));*/
			u.setId((Integer)res.getObject(1));
			u.setName((String)res.getObject(2));
			u.setScore((Integer)res.getObject(3));
			u.setTime((Date)res.getObject(4));//ע��������õ���sql�ķ���������Ҫ��util������ΪdbUser�е�����util��
			list.add(u);
			//���ֻ�ȡֵ�÷���  һ���� ���֣�һ�������������ʹ������
			/*System.out.println("ѧ��:"+res.getObject(1));
			System.out.println("����:"+res.getObject("name"));
			System.out.println("����:"+res.getObject(3));
			System.out.println("ע��ʱ��:"+res.getObject("time"));
			System.out.println("--------------------------------------");*/
		}
		//�ر���Դ
		res.close();
		state.close();
		conn.close();
		for(dbUser u:list){
			System.out.println(u);
		}
		
	}
}
