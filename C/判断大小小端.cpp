#include <iostream> 
using namespace std;

int main(){
	short a = 0x1020;
	char c = ((char *)&a)[0];
	if(c == 0x10){
		cout<<"���"<<endl;
	}else{
		cout<<"С��"<<endl;
	}
}
