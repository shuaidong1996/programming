#include <iostream>
using namespace std;

class B{
public:
	B(int a = 0){cout<<"B()"<<endl;}
	B &operator+=(const B &b){
		 cout<<"operator +="<<endl; 
		 return *this;
	}
	~B(){cout<<"~B()"<<endl;}
};
void test(){
	B b;
	b += 2;//�Ȱ�2��ʽת��ΪB Ȼ������� ע��ǰ�����ж�Ӧ�Ĺ��캯��
		//���� �� += ����һ��ǰ��� explicit �Ǿͱ��벻�� 
}
/*
B()
B()
operator +=
~B()
~B()
*/
int main() {
	test();
}
