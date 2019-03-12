/*
��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ����������������һ����ת�������ת�������СԪ�ء�
��������{3��4��5��1��2}Ϊ{1��2��3��4��5}��һ����ת�����������СֵΪ1��
����ʹ�ö��ֲ��ҷ�,ʱ�临�Ӷ�O(logN)��
*/

#include <iostream>
using namespace std;

int MidOn(int *arr, int first, int end)
{
	int min = arr[first];
	for (int i = first + 1; i<end; i++)
	{
		if (min > arr[first])
			min = arr[first];
	}
	return arr[min];
}

int Min(int arr[], int len)
{
	//	if(!arr || len <= 0)
	//		throw new std::exception("Invaild parameters");	//����

	int first = 0;
	int end = len - 1;
	int mid = first;															// ������������mid = first��Ŀ�ģ�����û����ת����ת����0������� 
	while (arr[first] >= arr[end])	//һ����˵first >= end  ����û����ת ������� 
	{
		if (first + 1 == end)
		{
			mid = end;
			break;
		}
		mid = (first + end) / 2;

		//��ǰ����м��������ȵ�����£�ֻ�ܱ���    ���� 1 0 1 1 1  
		if (arr[first] == arr[end] && arr[first] == arr[mid])
			return MidOn(arr, first, end);

		if (arr[mid] >= arr[first])
			first = mid;
		else if (arr[mid] <= arr[end])
			end = mid;
	}
	return arr[mid];
}

int main()
{
	//int arr[] = { 4, 5, 6, 1, 2, 3 };
//	int arr[] = { 1, 2, 3, 4, 5, 6, };
	int arr[] = { 1, 0, 1, 1, 1 };
	cout << Min(arr, sizeof(arr) / sizeof(arr[0])) << endl;
}

