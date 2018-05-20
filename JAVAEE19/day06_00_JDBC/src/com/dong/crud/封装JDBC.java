package com.dong.crud;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;

import com.dong.entity.dbUser;
import com.dong.util.DbUtils;

/*
 * ���з�װ֮��ÿ�ε��þͻ�򵥺ܶ࣬���˼���������
 */
public class ��װJDBC {
	@Test
	public void dbInsertUp() throws SQLException {
		Connection conn = DbUtils.getConnection();
		String sql = "INSERT INTO day06(`name`,`score`,`time`,`password`) VALUES(?,?,?,?)";
		PreparedStatement state = conn.prepareStatement(sql);

		// *****************************************
		state.setString(1, "����1");
		state.setInt(2, 99);
		state.setDate(3, new java.sql.Date(System.currentTimeMillis()));
		state.setString(4, "111");
		int res = state.executeUpdate();
		// *****************************************

		System.out.println("�ɹ��޸��ˣ�" + res + "��");
		DbUtils.closeAll(null, state, conn);
	}

	@Test
	public void dbInsert() throws SQLException {
		Connection conn = DbUtils.getConnection();
		Statement state = conn.createStatement();
		int res = state
				.executeUpdate("INSERT INTO day06(`name`,`score`) VALUES('���Ȼ�',77)");
		DbUtils.closeAll(null, state, conn);
		System.out.println("�ɹ��޸��ˣ�" + res + "��");
	}

	@Test
	public void dbDelete() throws SQLException {
		Connection conn = DbUtils.getConnection();
		Statement state = conn.createStatement();
		int res = state.executeUpdate("delete from day06 where name='���Ȼ�'");
		DbUtils.closeAll(null, state, conn);
		System.out.println("�ɹ��޸��ˣ�" + res + "��");
	}

	@Test
	public void dbSelect() throws SQLException {
		Connection conn = DbUtils.getConnection();
		Statement state = conn.createStatement();
		ResultSet rs = state.executeQuery("select * from day06");
		List<dbUser> list = new ArrayList<dbUser>();
		while (rs.next()) {
			dbUser u = new dbUser();
			u.setId(rs.getInt(1));
			u.setName(rs.getString(2));
			u.setScore(rs.getInt(3));
			u.setTime(rs.getDate(4));
			list.add(u);
		}
		DbUtils.closeAll(rs, state, conn);
		for (dbUser u : list) {
			System.out.println(u);
		}
	}
}
