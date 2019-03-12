#include <iostream>
using namespace std;

//����쳲���������

//���ظ�����ĵݹ飬Ч�ʼ��� 
long long Fibonacci(unsigned int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
 } 
 
//�ǵݹ��O(n)
long long Fibonacci2(unsigned int n)
{
	long long res[2] = {0,1};
	if(n <= 2)
		return res[n];
	long long sum;
	for(int i = 3;i<=n;i++)
	{
		sum = res[0] + res[1];
		res[0] = res[1];
		res[1] = sum;
	}
	return sum;
 } 
 
 
 int main()
 {
 	cout<<Fibonacci2(50)<<endl;
 	
 }
