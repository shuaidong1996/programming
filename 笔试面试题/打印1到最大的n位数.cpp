#include <iostream>
#include <cstring>
using namespace std;

/*��ӡ 1 ������ n λ��*/
//ÿ��Ϊ�ַ�������һ��1 
bool Increase(char *num,int n)
{
	num[n - 1]++;
	for(int i = n - 1;i>=0;i--)
	{
		if(num[i] > 9)
		{
			if(0 == i)
				return false;
			num[i-1]++;
			num[i] = 0;
		}
		else
			break;
	}
	return true;
}
//��ӡ���� 
void printStr(char *num,int n)
{
	bool start = false;
	for(int i = 0;i<n;i++)
	{
		if(!start && num[i])
			start = true;
		if(start)
			cout<<(int)num[i];
	}
	cout<<endl;
}
void PrintToMax(int n)
{
	char *num = new char[n + 1];
	memset(num,0,n + 1);
	while(Increase(num,n))
		printStr(num,n);
} 
/////////////////////////////���и��򵥵ķ��� �ݹ飬ȫ����˼��//////////////////////////////////
void print_sys(char *str,int n)
{
	char *s = NULL;
	for(int i = 0;i<n;i++)
	{
		if('0' != str[i])
		{
			s = str + i;
			break;
		}
	}
	if(s)//Ϊ�˴���ȫ��0����� 
		cout<<s<<endl;
}
void print(char *str,int n,int index)
{
	if(index == n)
		print_sys(str,n);
	else
		for(int i = 0;i<10;i++)
		{
			str[index] = i + '0';
			print(str,n,index + 1);
		}
} 

 void printToMax2(int n)
 {
 	char *str = new char[n + 1];
 	memset(str,0,n+1);
 	print(str,n,0);
} 
int main()
{
	PrintToMax(3);
	//printToMax2(3);
}
