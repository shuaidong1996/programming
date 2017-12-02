#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/*
�ڴ��ص�����:
Ҫ���ľ��ǣ�src�������ڲ�����copy֮ǰ���ı� 

Դ����ʵ�����ж��Ƿ���ڽ��棬���û����ô����memcpy���������ִ����������Ĵ���
*/ 
void *MemMove(void *dst, void *src, int n){
	if(!dst || !src || n <= 0)
		return dst;
	char *dst_ = (char *)dst;
	char *src_ = (char *)src;
	if(dst_ > src_){//src��ǰ����Ҫ�Ӻ���ǰcopy 
		while(--n > 0)
			*(dst_ + n) = *(src_ + n);
	}
	else{//��ǰ����copy 
		int idx = 0;
		while(idx < n){
			*(dst_ + idx) = *(src_ + idx);
			++idx;
		}
	}
	return dst;
}
void test(){
	char s[] = "1234567890";
	char* p1 = s;
	char* p2 = s+2;
	MemMove(p2, p1, 5);
	cout<<p1<<endl;
	
	char ss[] = "1234567890";
	p1 = ss;
	p2 = ss+2;
	MemMove(p2, p1, 5);
	cout<<p1<<endl;
}
void test2(){
	char s[] = "1234567890";
	char* p1 = s;
	char* p2 = s+2;
	MemMove(p1, p2, 5);
	cout<<p1<<endl;
	
	char ss[] = "1234567890";
	p1 = ss;
	p2 = ss+2;
	MemMove(p1, p2, 5);
	cout<<p1<<endl;
} 
int main(){
	test(); 
	test2();
}
