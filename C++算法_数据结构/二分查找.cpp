#include <iostream>
#include <vector>
using namespace std;
//��ͨ
int BinarySearch(vector<int> v, int key){
	int l = 0, r = v.size() - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (key > v[mid]){
			l = mid + 1;
		}
		else if (key < v[mid]){
			r = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
//���ҵ�һ����key���Ԫ��(����ͬkey ����ߵ��Ǹ�)
int BinarySearch2(vector<int> v, int key){
	int l = 0, r = v.size() - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (key > v[mid]){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if (l >= v.size()){
		l = -1;
	}
	return l;
}
//���ҵ�һ����key���Ԫ��(����ͬkey ���ұߵ��Ǹ�) -- ���������ܲ���ͬʱ����
int BinarySearch3(vector<int> v, int key){
	int l = 0, r = v.size() - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (key >= v[mid]){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if (l >= v.size()){
		l = -1;
	}
	//return l - 1;//����Ҫ -1 ������������������r-1������ѭ����  ������l+1������ѭ����  ������Ҫ l - 1 
	return r;	//����ͬkey ���ұߵ��Ǹ�
	return l;	//���ҵ�һ����key���Ԫ��
}
void test1(){
	int arr[] = { 0, 1, 2, 3, 6, 6, 6, 6, 7, 8, 9};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v(arr, arr + n);
	for(int i = 0; i < n; ++i)
		cout<<i<<"->"<<arr[i]<<endl;
	cout << "��6����ߵĽǱ꣺" << BinarySearch2(v, 6) << endl;
	cout << "��6���ұߵĽǱ꣺" << BinarySearch3(v, 6) << endl;
}
void test2(){
	int arr[] = { 0, 3, 6, 10, 12};
	int n = sizeof(arr) / sizeof(int);
	vector<int> v(arr, arr + n);
	for(int i = 0; i < n; ++i)
		cout<<i<<"->"<<arr[i]<<endl;
	cout << "�ҵ�һ����8��ĽǱ꣺" << BinarySearch2(v, 8) << endl;
	cout << "�ҵ�һ����8С�ĽǱ꣺" << BinarySearch3(v, 8) << endl;
}

int main() {
	test1();
	test2();
}
