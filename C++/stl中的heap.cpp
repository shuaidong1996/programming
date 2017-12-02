/*
make_heap��ʹ���б�ɶ�
push_heap��ѹջ(��ջ)
pop_heap����ջ(��ջ)
sort_heap���Զ�����
*/ 
#include <iostream>  
#include <algorithm>  
#include <vector>  
using namespace std;
  
int main () {  
	int myints[] = {10,20,30,5,15};  
	vector<int> v(myints,myints+5);  
	
	make_heap (v.begin(),v.end());
	cout << "initial max heap   : " << v.front() << endl;  
	
	pop_heap (v.begin(),v.end()); 
	v.pop_back();  
	cout << "max heap after pop : " << v.front() << endl;  
	
	v.push_back(99);
	push_heap (v.begin(),v.end());  
	cout << "max heap after push: " << v.front() << endl;  
	
	cout << "final sorted range :";  
	sort_heap (v.begin(),v.end()); 		 //������
	for (unsigned i=0; i<v.size(); i++)
		cout << " " << v[i];  
  
	return 0;  
}  
/*
initial max heap   : 30
max heap after pop : 20
max heap after push: 99
final sorted range : 5 10 15 20 99
*/ 
