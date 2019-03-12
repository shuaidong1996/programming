#include <iostream>
using namespace std;
/*
ģ��pow�Ĳ��ֹ���
ע�⣺1. base����Ϊ0�����=0 exp �Ͳ���Ϊ����
2. exp���Ϊ��������ô���������Ҫ��ɵ���
3. �������1�����������ô��Ҫһ����־��g_Invalid�����Ƿ�������
4. Ҫָ��0��0�η�����ѧ��û�����壬���۷���0����1���ܽ��ܣ����淵�ص���1
*/
bool g_Invalid = false;

bool isEqual(double num1, double num2)
{
	if (num1 - num2 < 0.0000001 && num1 - num2 > -0.0000001)
		return true;
	return false;
}
/*��������n�η���Ҫn��ѭ��(ÿ��*base)  ����������Ǽ��������8�η�����ô16�η�����8�η��Ľ����ƽ�� ѭ������������*/
double PowerWithUnsigned(double base, unsigned int exp)
{
	if (0 == exp)
		return 1;
	if (1 == exp)
		return base;
	double res = PowerWithUnsigned(base, exp >> 1);		//�� >> 1 ��ȡ�� / 2 
	res *= res;
	//�ж�ָ������������ż��  �������������Ҫ*base 
	if (exp & 1 == 1)									//�� & 1 ��ȡ�� % 2  
		res *= base;
	return res;
}
/*���������ͺ�low
double PWU(double base,unsigned int exp)
{
double sum = 1.0;
for(int i = 0;i<exp;i++)
sum *= base;
return sum;
}
*/
double Power(double base, int exp)
{
	if (isEqual(base, 0.0) && exp < 0)
	{
		g_Invalid = true;
		return 0.0;
	}

	/*Ϊ�˴���expΪ���������*/
	unsigned int absExp = (unsigned int)exp;
	if (exp < 0)
		absExp = (unsigned int)-exp;

	//������һ����Ч�㷨
	double res = PowerWithUnsigned(base, absExp);

	if (exp < 0)
		res = 1.0 / res;
	return res;
}


int main()
{
	cout << Power(5.0, 3) << endl;
	cout << Power(5.0, 0) << endl;
	cout << Power(0, 0) << endl;
	cout << Power(-3, 3) << endl;
	cout << Power(-1.2, 2) << endl;
	cout << Power(-3, -1) << endl;
	double res = Power(0, -1);
	if (g_Invalid)
		cout << "������" << endl;
	else
		cout << res << endl;
	return 0;
}
