#include <iostream>
using namespace std;

void swap(int &a, int &b){
	a ^= b;
	b ^= a;
	a ^= b;
}
/* С���� */
//����
void InsertHeap(int *arr, int i){
	if(!arr || i < 0)
		return;
	int fa = (i - 1) / 2;
	int temp = arr[i];
	while(i > 0){//Ϊɶֻ�ж��ӽڵ㣿 ��ΪֻҪi>0�����ڵ�Ͳ�����Ϊ����
		if(temp > arr[fa])
			break;
		arr[i] = arr[fa];
		i = fa;
		fa = (fa - 1) / 2;
	}
	arr[i] = temp;
}
//ͷ����³�
void HeadDownHead(int *arr, int n){
	if(!arr || n < 0)
		return;
	int i = 0;//ͷ���
	int l_child = 2 * i + 1;//����
	int temp = arr[i];
	while(l_child < n){
		//�ж����ҽڵ��ĸ���С
		if(l_child + 1 < n && arr[l_child + 1] < arr[l_child])
			++l_child;//��ڵ��Ϊ�ҽڵ�
		if(temp < arr[l_child])
			break;
		arr[i] = arr[l_child];
		i = l_child;
		l_child = 2 * l_child + 1;
	}
	arr[i] = temp;
}
//����
void HeadSort(int *arr, int n){
	if(!arr || n <= 0)
		return;
	//�Ȳ���
	for(int i = 0; i < n; ++i)
		InsertHeap(arr,i);
	//Ȼ�����������(С����  �ǴӴ�С����)
	for(int i = n - 1; i > 0; --i){
		swap(arr[i], arr[0]);
		HeadDownHead(arr,i);
	}
}
///////////////////////����///////////////////////////////
void test1()
{
	int arr[] = { 5, 8, 1, 6, 3, 4, 2, 9, 7 };

	HeadSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << "\t";
		if (i == 0 || i == 2 || i == 6)
			cout << endl;
	}
	cout << endl;
}
int main(){
	test1();
}
