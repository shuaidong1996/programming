#include <iostream>
#include <type_traits>
using namespace std;

template<typename T>
void print(){
	cout << "is_array:" << is_array<T>::value << endl;
	cout << "is_class:" << is_class<T>::value << endl;
	cout << "is_enum:" << is_enum<T>::value << endl;
	cout << "is_function:" << is_function<T>::value << endl;
	cout << "is_integral:" << is_integral<T>::value << endl;
	cout << "is_lvalue_reference:" << is_lvalue_reference<T>::value << endl;
	cout << "is_pointer:" << is_pointer<T>::value << endl;
	cout << "is_union:" << is_union<T>::value << endl;
	cout << "is_void:" << is_void<T>::value << endl;
	cout << "���������� ��ô:" << has_virtual_destructor<T>::value << endl;
	cout << "��ֵ ����Ҫ:" << is_trivially_assignable<T, T>::value << endl;
	cout << "���� ����Ҫ:" << is_trivially_constructible<T>::value << endl;
	cout << "������ֵ ����Ҫ:" << is_trivially_copy_assignable<T>::value << endl;
	cout << "�������� ����Ҫ:" << is_trivially_copy_constructible<T>::value << endl;
	cout << "Ĭ������ ����Ҫ:" << is_trivially_destructible<T>::value << endl;
	cout << "Ĭ�Ϲ��� ����Ҫ:" << is_trivially_default_constructible<T>::value << endl;
	cout << "move ��ֵ ����Ҫ:" << is_trivially_move_assignable<T>::value << endl;
	cout << "move ���� ����Ҫ:" << is_trivially_move_constructible<T>::value << endl;
	cout << "move ���� ��ô:" << is_move_constructible<T>::value << endl;
	cout << "move ��ֵ ��ô:" << is_move_assignable<T>::value << endl;
}
class A{
};
class B{
public:
	B(){}
	~B() = delete;
	B(const B &) = delete;
};
class C{
public:
	C(){ cout << "b" << endl; }
	virtual ~C(){}
	C(const C &) = default;//Ĭ�Ͼ�����copy���죬д��дһ�� 
	C(C &&) = delete;
	C &operator=(C &&) = delete;
};
int main(){
	cout << "-----------int---------------" << endl;
	print<int>();
	cout << "------------B--------------" << endl;
	print<A>();
	cout << "-----B(){} ~B()=delete; B(const B &)=delete;-----" << endl;
	print<B>();
	cout << "----C(){ cout }  virtual ~C(){}-----------" << endl;
	print<C>();
	getchar();
	return 0;
}
/*
-----------int---------------
-----------int---------------
-----------int---------------
is_array:0
is_class:0
is_enum:0
is_function:0
is_integral:1
is_lvalue_reference:0
is_pointer:0
is_union:0
is_void:0
���������� ��ô:0
��ֵ ����Ҫ:0
���� ����Ҫ:1
������ֵ ����Ҫ:1
�������� ����Ҫ:1
Ĭ������ ����Ҫ:1
Ĭ�Ϲ��� ����Ҫ:1
move ��ֵ ����Ҫ:1
move ���� ����Ҫ:1
move ���� ��ô:1
move ��ֵ ��ô:1
------------B--------------
is_array:0
is_class:1
is_enum:0
is_function:0
is_integral:0
is_lvalue_reference:0
is_pointer:0
is_union:0
is_void:0
���������� ��ô:0
��ֵ ����Ҫ:1
���� ����Ҫ:1
������ֵ ����Ҫ:1
�������� ����Ҫ:1
Ĭ������ ����Ҫ:1
Ĭ�Ϲ��� ����Ҫ:1
move ��ֵ ����Ҫ:1
move ���� ����Ҫ:1
move ���� ��ô:1
move ��ֵ ��ô:1
-----B(){} ~B()=delete; B(const B &)=delete;-----
is_array:0
is_class:1
is_enum:0
is_function:0
is_integral:0
is_lvalue_reference:0
is_pointer:0
is_union:0
is_void:0
���������� ��ô:0
��ֵ ����Ҫ:1
���� ����Ҫ:0
������ֵ ����Ҫ:1
�������� ����Ҫ:0
Ĭ������ ����Ҫ:0
Ĭ�Ϲ��� ����Ҫ:0
move ��ֵ ����Ҫ:1
move ���� ����Ҫ:0
move ���� ��ô:1
move ��ֵ ��ô:1
----C(){ cout }  virtual ~C(){}--C(C &&) = delete; ---------
is_array:0
is_class:1
is_enum:0
is_function:0
is_integral:0
is_lvalue_reference:0
is_pointer:0
is_union:0
is_void:0
���������� ��ô:1
��ֵ ����Ҫ:0
���� ����Ҫ:0
������ֵ ����Ҫ:0
�������� ����Ҫ:0
Ĭ������ ����Ҫ:0
Ĭ�Ϲ��� ����Ҫ:0
move ��ֵ ����Ҫ:0
move ���� ����Ҫ:0
move ���� ��ô:1	//����ط��͹�����һ������������0����Ϊ�Լ�delete�� 
move ��ֵ ��ô:1	//ͬ�� 
*/ 
