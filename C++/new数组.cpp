#include <iostream>
using namespace std;
//new����ֻ�ܵ���Ĭ�Ϲ��죬�������ö�λnew���Դﵽ�����������������
 
class A{
public:
	int a; 
    A(){ cout << "A()" << endl;}
    A(int a):a(a){ cout << "A(int a)" << endl; }
    ~A(){ cout << "~A()" << " a=" << a << endl; }
};

int main(){
	A *a = new A[10];
	A *tmp = a;
	for(int i = 0; i < 10; ++i)
		new (tmp++)A(2);
	delete[] a; 
}
