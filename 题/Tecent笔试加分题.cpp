/*�� ���ӷ���
28������һ����a[N]������ϣ����������b [N]������b[j]=a[0]*a[1]��a[N-1] / a[j]���ڹ�������У�������ʹ�ó�����
Ҫ��O��1���ռ临�ӶȺ�O��n����ʱ�临�Ӷȣ�
��������������a[N] b[N]�⣬����ʹ���µı���������ջ��ʱ�������ѿռ��ȫ�־�̬�����ȣ���
ʵ�ֳ����������������ѡ��ʵ�ֲ���������*/
#include <iostream>
using namespace std; 
void print(int arr[],int max)
{
	for(int i = 0;i<max;i++)
		cout<<arr[i]<<" "; 
}

int main()
{
	const int max = 5;
	int a[max] = {1,2,3,4,5};
	int b[max];
	b[0] = 1;
	for(int i = 1;i<max;i++)
		b[i] = b[i - 1] * a[i - 1];
	for(int i = max - 2; i >= 0; i--)
	{
		if(i != max - 2)
			a[max - 1] *= a[i + 1];
		b[i] *= a[max - 1];
	}
	print(b,max);
} 
