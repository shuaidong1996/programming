#include <typeinfo>
#include <cassert>
#include <iostream> 
using namespace std;

struct B {} b, c;

struct D : B {} d;

int main() {
    const std::type_info& tb = typeid(b); 
    const std::type_info& tc = typeid(c); 
    const std::type_info& td = typeid(d);
    assert(tb == tc);   // b��c������ͬ������
    assert(&tb == &tc); // tb��tc���õ�����ͬ�Ķ���
    assert(tb != td);   // ��ȻD��B�����࣬����b��d������ȴ��ͬ
    assert(&tb != &td); // tb��td���õ��ǲ�ͬ�Ķ���
    
    cout<<tb.name()<<endl;
    cout<<tc.name()<<endl;
    cout<<td.name()<<endl;
}
