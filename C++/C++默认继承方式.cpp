#include <iostream> 
using namespace std;
//class˽�м̳� 
class A{
public:
	int a;	
};
class B: A{}; 
class C: B{};
//struct���м̳�
struct A2{ int a; };
struct B2: A2{};
struct C2: B2{};

int main(){
	cout<<sizeof(C)<<endl;//4 ��Ȼ��˽�м̳У����಻���ã������ڴ��ϻ��ǵ�copy 
	cout<<sizeof(C2)<<endl;//4
//	C().a;	���붼��ͨ�� 
	C2().a;
}
