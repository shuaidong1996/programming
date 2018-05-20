/*
СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬����С���ж��ٶ��أ�������أ�
��������:
 �����������������ݡ�
 ����ÿ��������ݣ�
 N - �������������n����
 a1,a2...an - ��Ҫ���������
 ��֤:
 1<=N<=100000,0<=ai<=INT_MAX.
�������:
����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����
��������1:
6
45 12 45 32 5 6
�������1:
1 2

1.������
     ������������������֮��������������������ͬ��ֱ��������
         ���Ϊ���������� = ����С���� = ��n * (n-1))/2;(�������)
2.ͳ��������ÿ�����ֵĸ����������õ�map��
3.�������С����
    3.1.���������û���ظ����֣�˵����С�Ϊ0����С��϶��������������������Ĳ�
        ��ˣ�����һ�����飬���㲢ͳ����С�
    3.2.������������ظ����֣�˵����С����0����ʱ������һ��map�����ָ�����Ϊ0��
        ���ֻ������С��0�����ù�ʽ���㼴��
4.�����������
    ֻ��һ����������ֵ����Сֵ��������ϣ������ֵ���� * ��Сֵ����
�㷨���Ӷȣ�����O(nlogn), ͳ��O(n)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void CountMin(vector<int> &v){
	if(v.empty())
		return;
	int count = 0, size = v.size();
	map<int, int> m;
	bool flag = false;
	for(int i = 0; i < size; ++i){
		auto it = m.find(v[i]);
		if(it == m.end()){
			m.insert(make_pair(v[i], 1));
		}
		else{
			++m[v[i]];
			flag = true; 
		}
	}
	if(flag){
		int num;
		for(auto it = m.begin(); it != m.end(); ++it){
			num = it->second;
			count += num * (num - 1) / 2;
		}
	}
	else{
		int min = 0x7fffffff;
		for(int i = 1; i < size; ++i){
			if(v[i] - v[i - 1] == min)
				count++;
			else if(v[i] - v[i - 1] < min){
				min = v[i] - v[i - 1];
				count = 1;
			}
		}
	}
	cout << count << " ";
}
void CountMax(vector<int> &v){
	if(v.empty())
		return;
	int min = v[0], minCount = 0;
	for(auto it = v.begin(); it != v.end(); ++it){
		if(min == *it)
			++minCount;
		else
			break;
	}
	int max = *v.rbegin(), maxCount = 0;
	for(auto it = v.rbegin(); it != v.rend(); ++it){
		if(max == *it)
			++maxCount;
		else
			break;
	}
	cout << minCount * maxCount << endl;
}
void Count(vector<int> v){
	if(v.empty())
		return;
	sort(v.begin(), v.end());
	int size = v.size();
	if(v[0] == v[size - 1]){
		int count = size * (size - 1) / 2;
		cout << count << " " << count << endl; 
	}
	else{
		CountMin(v);
		CountMax(v);
	}
}
int main(){
	int n;
	while(cin >> n){
		vector<int> v;
		int num;
		while(n-- > 0){
			cin >> num;
			v.push_back(num);
		}
		Count(v);
	}
} 

