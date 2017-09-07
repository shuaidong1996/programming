package test;

import java.util.*;

public class Test {
	public static void main(String[] args) {
		System.out.println("start java");
		testString5();
	}
	static void testString(){
		System.out.println("hello".length());
	}
	static void testString2(){
		String str = new String("hello world");
		
		System.out.println(str.charAt(4));
		
		System.out.println(str.indexOf('o'));
		
		System.out.println(str.substring(1,3));
		
		System.out.println(str.substring(1));
		
	}
	static void testString3(){
		String s = new String("aaa");
		System.out.println(s instanceof String);
		System.out.println("dong" instanceof String);//false 这里进行了自动装箱，dong是一个对象，，但是js中这里是false
	}
	static void testString4(){
		String s = "123";
		System.out.println(Integer.parseInt(s));
		
		s+=4;
		System.out.println(Integer.parseInt(s));
		
		// js中可以  parseInt(s);//因为js中是从左到右依次转化，直到不能转化为止    
//		s+="a";									//java中不行
//		System.out.println(Integer.parseInt(s));  
	}
	static void testString5(){
		//int[] arr = [1,2,3,4];
		int[] arr = {1,3,6,4};
		System.out.println(Arrays.toString(arr));
		
		Arrays.sort(arr);
		System.out.println(Arrays.toString(arr));//注意：Arrays不能new  因为他的构造函数是私有的
	}
}
