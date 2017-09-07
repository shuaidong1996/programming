#include<iostream>
using namespace std;

//只要有虚函数，基类，派生类都会默认创建一个指向虚函数表的指针，表可能不一样
class A{
public:
	virtual void go1()
	{
		cout << "A  go1" << endl;
	}
	virtual void go2()
	{
		cout << "A  go2" << endl;
	}
	virtual void go3()
	{
		cout << "A  go3" << endl;
	}
};
class B:public A{
public:
	void go2()
	{
		cout << "B  go2" << endl;
	}
private:
	void go3()
	{
		cout << "B  go3" << endl;
	}
};
int main()
{
	B b;
	cout << &b << endl;//B类的基址，也是虚函数的首地址
	cout << *((int *)&b) << endl;//vptr指针指向了虚表，打印的就是虚表的地址（十进制表示）
	cout << (int *)*((int *)&b) << endl;//虚表的地址（16进制表示）(我强制把数字转化成了地址)  步长为4
	cout << (void *)*((int *)&b) << endl;//步长为1，，就这点区别
	//所以下面所有的void*都可以省略
	cout << "g1的地址：" << (void *)*(int *)*((int *)&b) << endl;//虚表中存放的也是一个一个函数指针，拿我这个类来说虚表中第一个元素就是指向go1的函数指针\
				我们得到虚表地址后再次进行强转(int*)  这样就找到了 虚表中第一个指针 的 地址\
				上面只是找到了，虚表中指针的地址，但是我们需要的是这个指针上存放的地址（go1的地址）所以再次取内容*
	cout << "g2的地址：" << (void *)(*((int *)(*((int *)&b)) + 1)) << endl;
	cout << "g3的地址：" << (void *)(*((int *)(*((int *)&b)) + 2)) << endl;
	
	cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
	cout << "------------不创建类对象也能调用类中的非静态函数------------" << endl;
	cout << "----------------在外部也能调用类中私有函数------------------" << endl;
	cout << "★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★" << endl;

	typedef void(*P)();
	for (int i = 0; i < 3; i++)
	{
		((P)(*((int *)(*((int *)&b)) + i)))();//看到这一串代码不是不疯了
	}
	cout << "-----------------代码简化--------------------" << endl;
	P p[3];
	for (int i = 0; i < 3; i++)
	{
		p[i] = (P)(*((int *)(*((int *)&b)) + i));
		p[i]();
	}
	system("pause");
}
/*
007EFAB4
514692
0007DA84
0007DA84
g1的地址：0007144C
g2的地址：00071249
g3的地址：0007121C
☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆
------------不创建类对象也能调用类中的非静态函数------------
----------------在外部也能调用类中私有函数------------------
★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★
A  go1
B  go2
B  go3
-----------------代码简化--------------------
A  go1
B  go2
B  go3
*/