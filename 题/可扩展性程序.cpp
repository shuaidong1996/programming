#include <iostream>
using namespace std;
/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

���ٻ��ʣ�����ǰ������֣�����%3==0 ���أ�
��ô����Ҫ���ǳ���Ŀ���չ�� �� �������� 
*/ 
void Reorder(int *arr,int len,bool func(int))
{
	if(!arr || len <= 0) return;
	int first = 0;
	int end = len - 1;
	while(first < end)
	{
		while(first < end && !func(arr[first]))
			first++;
		while(first < end && func(arr[end]))
			end--;
		if(first < end)
		{
			arr[first] += arr[end];
			arr[end] = arr[first] - arr[end];
			arr[first] = arr[first] - arr[end];
		}
	}
}
/*�ж�һ�����Ƿ���ż��*/ 
bool isEven(int n)
{
	return (n & 0x1) == 0; 
} 
/*�ж�һ�����Ƿ����ܱ�3����*/ 
bool is3(int n)
{
	return n % 3 == 0;
} 
/////////////////////////////////////////////////////
void test1()
{
//	int arr[] = {1,2,3,4,5,5,6,7,8};
//	int arr[] = {}; 
	int n = sizeof(arr) / sizeof(arr[0]);
	Reorder(arr,n,isEven);
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
 } 
void test2()
{
	int arr[] = {3,1,4,5,6,7,8,9,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	Reorder(arr,n,is3);
	for(int i = 0; i < n ;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	test2();
}

