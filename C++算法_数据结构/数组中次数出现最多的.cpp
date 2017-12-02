#include <iostream>
#include <map> 
using namespace std;

//�����������г��ִ��������Ǹ���������ж�����������С�� 
//1.������������һ��  �и�O(N)���㷨
 
//2.��hash����ã�����2�и����� ������Լ�����hash����  ��Ҫ������ĿҪ����ܹ������ĺ�����
//								�������������hash���� ���key�Ͳ��Ǵ�С��������ģ� 

//3.hash����ʵ���Ի���map  ����ʱ�临�ӶȾͱ����NlogN ���ǲ��ÿ���key��
void findMaxNum(int *arr, int len){
	map<int, int> hmp;//ʹ��stlĬ�ϵ�hash�������е㲻̫����
	for(int i = 0; i < len; ++i){
		auto it = hmp.find(arr[i]);
		if(it == hmp.end())
			hmp[arr[i]] = 1;
		else
			++hmp[arr[i]];
	}
	int max = 0, max_num; 
	for(auto m : hmp){
		if (max < m.second){
			max_num = m.first;
			max = m.second;
		}
		cout << m.first << " -> " << m.second << endl;
	}
	cout << max_num << endl;
}

int main(){
	int arr[] = {4,5,3,4,3,4,9,10,3};
	findMaxNum(arr, sizeof(arr) / sizeof(arr[0]));
}
