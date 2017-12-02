#include <iostream>
#include <vector> 
#include <algorithm>
#include <functional>
#include <cstdlib>
using namespace std;
/* �ҳ��� K �����*/
template<typename T>
T partition(vector<T> &v, int left, int right)/*�Ӵ�С����  ���Ҫ������K����������ʹ�С�����һ��*/
{
	T t = v[left];
	while (left < right)
	{
		while (left < right && t > v[right])
			right--;
		v[left] = v[right];
		while (left < right && t <= v[left])
			left++;
		v[right] = v[left];
	}
	v[left] = t;
	return left;
}
/*��left - right �����ڵ�k�����*/
template<typename T>
T search_K(vector<T> &v, int left, int right, int k)
{
	if (k == 0 && left == right)
		return v[left];
	int pos = partition(v, left, right);//pos���λ�ò����ٱ��ƶ�
	int curK = pos - left + 1;//��ǰ��������curK�����   + 1����Ϊ�����Ǵ�0�±꿪ʼ��
	if (curK > k)
		return search_K(v, left, pos - 1, k);
	else if (curK < k)
		return search_K(v, pos + 1, right, k - curK);
	return v[pos];
}
template<typename T>
T search_K(vector<T> v, int n, int k)
{
	return search_K<int>(v, 0, n - 1, k);
}

int main()
{
	vector<int> v;
	int n = 20;
	for (int i = 0; i<n; ++i)
	{
		v.push_back(rand() % 100);
		cout << v[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; ++i)
		cout << "��" << i << " �����:" << search_K<int>(v, n, i) << endl;

	sort(v.begin(), v.end(),greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
