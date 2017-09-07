
class A{
	String name;
	int age;
	public A(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}
	
}
class B implements Cloneable {
	String name;
	int age;
	
	public B(String name, int age) {
		super();
		this.name = name;
		this.age = age;
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		return super.clone();
	}
	
}
public class Clone {
	public static void main(String[] args) throws Exception {
		A a = new A("��",12);
		B b = new B("��",20);
		
		A aa = a;					//ǳ����
		B bb = (B) b.clone();		//���
		aa.name = "dong";
		bb.name = "chen";
		
		System.out.println(a.name+"\t"+a.age);
		System.out.println(b.name+"\t"+b.age);
	}
}
