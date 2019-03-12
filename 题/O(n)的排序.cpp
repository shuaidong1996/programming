#include <iostream>
using namespace std;
/* �Լ���Ա������������ʱ��Ч��O(n) �����ڴ治����O(n)*/

void SortAges(int *age,int len)
{
	int oldestAge = 100;//�����ϵģ��ܻ�100��
	int timesOfAge[oldestAge];
	for(int i = 0;i<oldestAge;i++)
		timesOfAge[i] = 0;
	for(int i = 0;i<len;i++)
		timesOfAge[age[i]]++;
	
	int index = 0; 
	for(int i = 0 ;i<oldestAge;i++)
		for(int j = 0;j<timesOfAge[i];j++)
			age[index++] = i;
} 

int main()
{
	int age[] = {18,18,19,20,50,40,30,45,34,46,34,62,43,58,69,23,45,65,55,65,67,34,34,56,43,58,69,23,45,65,55,65,67,34,34,56};//����������Ա�������� 
	int n = sizeof(age) / sizeof(age[0]);
	SortAges(age,n);
	for(int i = 0;i<n;i++)
		cout<<age[i]<<" ";
}
