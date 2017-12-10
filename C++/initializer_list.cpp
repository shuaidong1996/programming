#include <iostream>
#include <vector>
#include <deque>
#include <typeinfo>
using namespace std;
/*
��֪��C++11������һ���б��ʼ��
�磺int a{1};
*/ 
void test(){
	int a{1};
	char b[5]{1,2,3,4};
	vector<int> v{1,2,4};
	deque<int> d{7,8,9}; 
}
/*
�����������͵�ȷ����������
���Ƕ��ںܶ��ࣺvector/deque...��˵��ô��{}��Ӧ�Լ��أ� ʵ�������ṩ��һ�� initializer_list ��ôһ����
���� { } ���ᱻ��ʽת��Ϊ initializer_list
stl_vector.h���� �����˹��캯�� {1,2} �ᱻĬ��ת��Ϊһ�� initializer_list �� 
vector(initializer_list<value_type> __l,
	     const allocator_type& __a = allocator_type())
      : _Base(__a)
      {
	_M_range_initialize(__l.begin(), __l.end(),
			    random_access_iterator_tag());
      }
���캯���������ѭ��{1,2,3}�����ֵ
*/

class B{
public:
	explicit B(int a, int b){cout<<a<<","<<b<<endl;}
	explicit B(initializer_list<int> __l){
		for(auto l : __l)
			cout<<l<<" ";
		cout<<endl;
	}
	B(const B &b){cout<<"copy B()"<<endl;} 
}; 
void test2(){
	B b1(1,2);
	B b2{1,2};
	B b3({1,2});
	B b4({1,2,3});
//	B b5 = {1,2}; converting to 'B' from initializer list would use explicit constructor 'B::B(std::initializer_list<int>)'
//	B b6 = {1,2,3};
} 
int main() {
	cout<<__cplusplus<<endl; 
	test();
	test2();
}
