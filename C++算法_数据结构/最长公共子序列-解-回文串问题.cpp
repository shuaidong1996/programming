/*
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
�����Ҫɾ�����ַ�������
��������1:
abcda
google
�������1:
2
2
*/
#include <iostream>
#include <string>
using namespace std;
int max(int a, int b){
	return a > b ? a : b;
}
int Construct(string str){
	int size = str.size();
	int *arr[size + 1];
	for(int i = 0; i < size + 1; ++i)
		arr[i] = new int[size + 1]();
	int m = 0;
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(str[i] == str[size - 1 - j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
		}
	}
	return size - arr[size][size];	
}

int main(){
	string str;
	while(cin >> str){
		cout << Construct(str) << endl;
	}
}
