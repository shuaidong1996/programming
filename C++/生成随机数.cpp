#include <iostream>
#include <random>
#include <ctime>
using namespace std;
#if 0
//rand����ķ�Χ�� 0 - 32767 
#define N 100000
int test(){
	srand(time(0));
	int num;
	for(int i = 0; i < N; ++i){
		num = rand();
		if(num > 32760)
			cout<<num<<endl;
	}
	return 0;
} 
#endif

//c++11�ṩ��<random>ʵ����������� https://www.cnblogs.com/byhj/p/4149467.html
#define N 0x7fffffff
int main(){
	default_random_engine e;//����ֱ��������ı����� e(10) 
	e.seed(time(0)); //�����µ�����
    for (size_t i = 0; i < 10; ++i) //����ʮ������� 
       cout << e() << endl; 
    cout << "Min random:" << e.min() << endl; //�����������������еķ�Χ 
    cout << "Max random:" << e.max() << endl; 
    return 0;
}
