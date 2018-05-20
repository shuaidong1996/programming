#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring> 
using namespace std;

//��һ��C����ת��(��ǰһֱϲ����  sprintf ����ǿ��)
void test()
{
	char *s = "dong";
	int a = 52;
	float b = .1314;
	char *buf = new char[strlen(s) + sizeof(a) + 1];
	sprintf(buf, "%s%d%.4f", s, a, b);
	printf("%s\n", buf);
}
//��C��C++���
void test1()
{
	string s = "dong";
	int a = 520;
	char *buf = new char[10];//2147483647 int���ֵ
	_itoa(a, buf, 10);		//itoa��Ȼ����ת��Ϊ���ֽ��ƣ�����ע�ⲻ����float����double
	cout << s + buf << " | ";
	_itoa(a, buf, 16);
	cout << s + buf << endl;
}
//��C++���
void test2()
{
	string s = "������";
	int a = 52;
	double b = .1314;
	ostringstream oss;
	oss << s << a << b;
	cout << oss.str() << endl;
}
//C++11������
void test3()
{
	int a = 520;
	float b = 5.20;
	string str = "dong";
	string res = str + to_string(a);
    cout << res << endl;
    res = str + to_string(b);
    res.resize(8);
    cout << res << endl;
}
int main()
{
	test();
	test1();
	test2();
	test3();
	return 0;
}
