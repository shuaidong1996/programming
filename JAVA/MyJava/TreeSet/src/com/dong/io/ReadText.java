package com.dong.io;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReadText {
	/*
	 * 读取文件，以行为单位读取文件内容，一次读一整行
	 */
	public List read(String fileName){
		File file = new File(fileName);
		BufferedReader br = null;
		List<String> arrayList = new ArrayList<String>();
		String str;
		try {
			br = new BufferedReader(new FileReader(fileName));
			// 一次读入一行，直到读入null为文件结束
			while((str = br.readLine())!=null){
				arrayList.add(str);
			}
			br.close();
		} catch (Exception e) {
			e.printStackTrace();
		}finally{
			if(br == null){
				try {
					br.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
		return arrayList;
	}
	
	String[] split(String str){
		String[] split = str.split(",");
		return split;
	}
}
