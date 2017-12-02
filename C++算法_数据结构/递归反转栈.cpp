#include <iostream>
#include <stack>
using namespace std;
//д���뷴תջ������������һ��ջ�����������飬ֻ���õݹ�

//����Ƚ��� http://www.cnblogs.com/4everlove/p/3666016.html
void ReverseStack(stack<int> &s){
	if(s.empty() || s.size() == 1)
		return;
	int top = s.top();
	s.pop();
	ReverseStack(s);//��η�תֻΪ�õ��������Ԫ�� 
	int bottom = s.top();
	s.pop();
	ReverseStack(s);//��ջ��ԭ 
	s.push(top);
	ReverseStack(s);//��תջ���������Ԫ�ص�������
	s.push(bottom);
}
//����Ƚϼ�  ��һ���µĺ����������Ѷ���Ԫ�طŵ�������
void PushBack(stack<int> &s, int size, int num){
	if(size == 0){
		s.push(num);
		return;
	}
	int top = s.top();
	s.pop();
	PushBack(s, size - 1, num);
	s.push(top);
}
void ReverseStack2(stack<int> &s, int size){
	if(s.empty() || size <= 1)
		return;
	int top = s.top();
	s.pop();
	PushBack(s, size - 1, top);
	ReverseStack2(s, size - 1);
} 
int main(){
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    ReverseStack2(s,s.size());
    while(!s.empty()){
    	cout<<s.top()<<endl;
    	s.pop();
	}
}
