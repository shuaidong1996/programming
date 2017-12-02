#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
//Ϊ��������Щ����û����

/* ���� */ 
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int SplitByMid1(int *arr, int left, int right){
	if (!arr || left < 0 || right < left)
		return -1;
	int index = left;
	int pivot = arr[right];  //ѡ�����Ҳ��Ԫ����Ϊ�ָ��׼  
	//������С�ڱ�׼�ĵ��ƶ���index�����    
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot)
			swap(arr[index++], arr[i]);
	}
	//����׼��indexָ���Ԫ�ؽ���������index�����ָ�λ��  
	swap(arr[right], arr[index]);
	return index;
}
void QuickSort1(int *arr, int left, int right){
	if (left < right){
		int mid = SplitByMid1(arr, left, right);
		QuickSort1(arr, left, mid - 1);
		QuickSort1(arr, mid + 1, right);
	}
}

/* ��ֵ */ 
int SplitByMid2(int *arr, int left, int right){
	if (!arr || left < 0 || right < left)
		return -1;
	int pivot = arr[left];
	while (left < right){
		while (left < right && arr[right] >= pivot)
			--right;
		arr[left] = arr[right];
		while (left < right && arr[left] <= pivot)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	return left;
}
void QuickSort2(int *arr, int left, int right){
	if (left < right){
		int mid = SplitByMid2(arr, left, right);
		QuickSort2(arr, left, mid - 1);
		QuickSort2(arr, mid + 1, right);
	}
}

/* ��ֵ + ����ȡ�� */
int median3(int arr[], int first, int median, int end){
	if (arr[first]<arr[median])	{
		if (arr[median]<arr[end])
			return median;
		else if (arr[first]<arr[end])
			return end;
		else
			return first;
	}
	else if (arr[first]<arr[end])
		return first;
	else if (arr[median]<arr[end])
		return end;
	else
		return median;
}
int SplitByMid3(int *arr, int left, int right){
	if (!arr || left < 0 || right < left)
		return -1;
	if(right - left >= 10){//������������޸� ���>=3 ��Ϊ <3��ȫû�б�Ҫ������ȡ�� 
		int mid = median3(arr, left, left + (right - left) / 2, right); 
		swap(arr[left], arr[mid]);
	} 
	int pivot = arr[left];
	while (left < right){
		while (left < right && arr[right] >= pivot)
			--right;
		arr[left] = arr[right];
		while (left < right && arr[left] <= pivot)
			++left;
		arr[right] = arr[left];
	}
	arr[left] = pivot;
	return left;
}
void QuickSort3(int *arr, int left, int right){
	if (left < right){
		int mid = SplitByMid3(arr, left, right);
		QuickSort3(arr, left, mid - 1);
		QuickSort3(arr, mid + 1, right);
	}
}

/* ��ֵ + ����ȡ�� + ����һ��ݹ� */
void QuickSort4(int *arr, int left, int right){
	while (left < right){
		int mid = SplitByMid3(arr, left, right);
		QuickSort4(arr, left, mid - 1);
		left = mid + 1;
	}
}

/* ��ֵ + ����ȡ�� + ����һ��ݹ� + �������� */ //ʱ�����ı�ǰ���ܶ�ܶ�  ��֪����ʲôԭ�� 
void InsertSort(int *arr, int l, int right){
	int temp, j;
	for(int i = 1; i < right; ++i){
		temp = arr[i];
		for(j = i - 1; j >= 0; --j){
			if(temp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = temp;
	}
} 
void QuickSort5(int *arr, int left, int right){
	if(right - left < 16){
		InsertSort(arr, left, right);
		return; 
	}
	if(left < right){
		int mid = SplitByMid3(arr, left, right);
		QuickSort5(arr, left, mid - 1);
		QuickSort5(arr, mid + 1, right); 
	}
}

#define N 10000000
//���һ���Լ���������û������ 
bool check(int *arr, int len){
	int i = 0;
	while (++i < len){
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}
void test1(){
	//�������100W����
	int *arr = new int[N];
	default_random_engine e(time(0)); 
	int i = 4;
	while (--i != 0){
		for (int i = 0; i < N; ++i)
			arr[i] = e();
		clock_t start, end;
		start = clock();
		QuickSort1(arr, 0, N - 1);
		end = clock();
		cout << "��ͨ���ţ�" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
		if (!check(arr, N))
			cout << "�������" << endl;

		for (int i = 0; i < N; ++i)
			arr[i] = e();
		start = clock();
		QuickSort2(arr, 0, N - 1);
		end = clock();
		cout << "��ֵ��" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
		if (!check(arr, N))
			cout << "�������" << endl;

		for (int i = 0; i < N; ++i)
			arr[i] = e();
		start = clock();
		QuickSort3(arr, 0, N - 1);
		end = clock();
		cout << "��ֵ+����ȡ�У�" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
		if (!check(arr, N))
			cout << "�������" << endl;

		for (int i = 0; i < N; ++i)
			arr[i] = e();
		start = clock();
		QuickSort4(arr, 0, N - 1);
		end = clock();
		cout << "��ֵ+����ȡ��+���ٵݹ飺" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
		if (!check(arr, N))
			cout << "�������" << endl;
			
//		for(int i = 0; i < N; ++i)
//			arr[i] = e();
//		start = clock();
//		QuickSort5(arr, 0, N - 1);
//		end = clock();
//		cout << "��ֵ+����ȡ��+���ٵݹ�+���룺" << (double)(end - start ) / CLOCKS_PER_SEC << "��" << endl;
//		if(!check(arr, N))
//			cout<<"�������"<<endl;

		for (int i = 0; i < N; ++i)
			arr[i] = e();
		start = clock();
		sort(arr, arr + N);
		end = clock();
		cout << "sort����" << (double)(end - start) / CLOCKS_PER_SEC << "��" << endl;
		if (!check(arr, N))
			cout << "�������" << endl;
		cout << "--------------------------" << endl;
	}
}

void test2(int a){
}
int main(){
	test1();
}
