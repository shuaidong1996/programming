#include <iostream>
using namespace std; 

//�����г�һ������ֻ����1���⣬�������ֶ��ɶԳ��֣�Ҫ�󾡿��ҳ��������
//��ô�й��ɿ϶�ʱ�临�Ӷ���O(N) ���������λ����
int test1(int arr[],int len)
{
	int temp = 0;
	for(int i = 0;i<len;i++)
		temp ^= arr[i];
	return temp;
}

//�������������������ͬ������������ȫ�ǳɶԵ�
//˼·���Ѳ�ͬ�����������ڲ�ͬ�����������У�Ȼ��˼·�ͺ�����һ����
void FindTwoNum(int arr[],int len,int &num1,int &num2)
{
	//�ҵ���ͬ����������^ 
	int temp = 0; 
	for(int i = 0;i<len;i++)
		temp ^= arr[i];
	//������������Ӷ����Ƶ���һλ��ʼ��ͬ�� (��ǰ��󣬴Ӻ���ǰ���У�ֻҪ�ҳ����������������ֵĵ�ͺ���)
	int i = 0;
	for(;i<sizeof(int) * 8;i++)
	 	if((temp >> i & 1) == 1)			// ע�� ���ȼ�  >> == &  һ�ν���    ��д���� (temp >> i) & 1 == 1 
	 		break;
	//���ھͿ����ҳ���������
	num1 = num2 = 0;
	for(int j = 0;j<len;j++)
		if((arr[j] >> i & 1)== 0)
			num1 ^= arr[j];
		else
			num2 ^= arr[j];
} 

int main()
{
//	int arr[] = {5,5,6,6,3,2,3,8,8};
//	cout<<test1(arr,sizeof(arr) / sizeof(arr[0]));
	int arr[] = {5,5,6,9,6,3,3,2,8,8};
	int a,b;
	FindTwoNum(arr,sizeof(arr) / sizeof(arr[0]),a,b);
	cout<<"a = "<<a<<"    "<<"b = "<<b<<endl;
}
