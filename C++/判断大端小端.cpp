#include <iostream>
using namespace std;

int main(){
	short a = 0x1234;
	char *b = (char *)&a;//ָ����a����ʼ��ַ 
	if(*b == 0x12)//�����ʼ��ַΪ0x12˵���Ǵ�� 
		cout<<"���"<<endl;
	else if(*b == 0x34)
		cout<<"С��"<<endl; 
} 
