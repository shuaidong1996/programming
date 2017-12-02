#include <iostream>
#include <ctime>
using namespace std;
//��ָOffer��������������S,��ӡ�����к�ΪS�������������У����ٺ�������������
//1 2 3 4 5 = 4 5 6 = 7 8 = 15
/*��ָoffer�ϵĽⷨ,�о����ϴ��벻����,�Լ��޸���һ��*/
void printadd(int min, int max, int sum)
{
	for (; min < max; min++)
		cout << min << " + ";
	cout << min << " = " << sum <<endl; 
}
void FindContinuousSequence(int n)
{
	int min = 0, max = 1, sum = 1;
	while(min <= n / 2)
	{
		if(sum == n)
		{
			printadd(min, max, sum);
			cout<<"--------------------------------------------------------------------"<<endl;
		}
		else if(sum > n)
		{
			sum -= min;
			++min;
			continue;
		}
		sum += ++max;
	}
}
//ʱ�临�Ӷ�Ϊ O(logN) 
void FindContinuousSequence2(int n)
{
	int min, max, count = 2;
	do
	{
		min = n / count - (count - 1) / 2;
		max = min + count - 1;
		++count;
		int sum = 0;
		for (int i = min; min>0 && i <= max; ++i)
			sum += i;
		if (sum == n)
		{
			printadd(min, max, sum);
			cout<<"--------------------------------------------------------------------"<<endl;
		}
	} while (min > 0);
}
void test1(int a)
{
	struct timeb startTime , endTime;
	ftime(&startTime);
	FindContinuousSequence(a);
	ftime(&endTime);
	cout << "test1��ʱ��" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;  
} 
void test2(int a)
{
	struct timeb startTime , endTime;
	ftime(&startTime);
	FindContinuousSequence2(a);
	ftime(&endTime);
	cout << "test2��ʱ��" << (endTime.time-startTime.time)*1000 + (endTime.millitm - startTime.millitm) << "����" << endl;  
}
int main()
{
	//int a = 0x7ffff;
	int a = 43124321;
	test1(a);
	cout<<"============================================================================="<<endl; 
	test2(a);
	cout<<"============================================================================="<<endl; 
}
