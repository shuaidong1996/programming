package com.dong.user;

public class User {
	public String level;
	public String name;
	public String score;
	public User() {
		super();
	}

	public User(String level, String name, String score) {
		super();
		this.level = level;
		this.name = name;
		this.score = score;
	}

	public String getLevel() {
		return level;
	}
	public void setLevel(String level) {
		this.level = level;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getScore() {
		return score;
	}
	public void setScore(String score) {
		this.score = score;
	}

	
}
