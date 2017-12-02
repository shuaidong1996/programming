#include <iostream>
#include <cstring>
using namespace std;

class Dong
{
private:
	char *str;
public:
	Dong(const char *s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	//1.����ֵҪ����*this�����ã��������ȣ�   2.��ֵ��&������û�иı䴫������ֵ����ʡ�ڴ棩
	Dong &operator =(const Dong &d)
	{
		//3.�ж��Ƿ���Լ����
		if (this == &d) return *this;

		//4.delete�Լ�ָ����ڴ�
		delete[] str;
		str = NULL;//����Ұָ��
		str = new char[strlen(d.str) + 1];
		strcpy(str, d.str);
		return *this;
	}
	~Dong()
	{
		delete[] str;
		str = NULL;
	}
};
//////////////////////����4�������Ѿ���ȫ���ˣ�����û�п��ǵ���ȫ����/////////////////////
/////////////////////////////new���ܲ��ɹ��׳��쳣////////////////////////////////////////
class DongUP
{
private:
	char *str;
public:
	DongUP(const char *s) 
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	//��������Ⱦ�������һ��temp���洢ԭ����str����str����һ��ʼ�ͱ�delete
	DongUP &operator =(const DongUP &d)
	{
		if (this != &d)
		{
			//��Ҫcopy���ڴ�ŵ�tempStr��
			char *tempStr = new char[strlen(d.str) + 1];
			strcpy(tempStr, d.str);
			//����tempStr��str��ָ��ָ��
			char *temp = tempStr;
			tempStr = str;
			str = temp;
			//�ͷ�ԭ��strָ����ڴ�
			delete[] tempStr;
		}
		return *this;
	}
	~DongUP()
	{
		delete[] str;
		str = NULL;
	}
};
int test2()
{
	DongUP d("chen");
	DongUP d2("shuaidong");
	DongUP d3("a");
	d3 = d2 = d;
	return 0;
}
int test1()
{
	Dong d("chen");
	Dong d2("shuaidong");
	Dong d3("a");
	d3 = d2 = d;
	return 0;
}
int main()
{
	test1();
	test2();
}
