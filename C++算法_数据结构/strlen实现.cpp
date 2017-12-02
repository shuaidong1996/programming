#include <iostream>
#include <cstring>
using namespace std;

//strlen������ʵ�ַ�ʽ
int Strlen1(const char *str) {
	if(!str) return -1;
	int i = 0;
	while(*str++ != 0)
		++i;
	return i;
}
int Strlen2(const char *str) {
	if(!str) return -1;
	const char *end = str;
	while(*end++);
	return end - str - 1;
}
//�ݹ�->��ʹ���κα��� 
int Strlen3(const char *str) {
	if(!str) return -1;
	return *str == 0 ? 0 : Strlen3(str + 1) + 1;
}

int main(){
	const char *p = "hello dong";
	cout << strlen(p) << endl;
	cout << Strlen1(p) << endl;
	cout << Strlen2(p) << endl;
	cout << Strlen3(p) << endl;
}
