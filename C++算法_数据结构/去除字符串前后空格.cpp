#include <iostream> 
#include <cstring>
using namespace std;
//һ������ʵ�ָ����ַ�����ȥ��ǰ��ͺ���Ŀո񣬱��硰 ab cd ��
//���õ��Ľ����"ab cd"�����ܸı��ַ����ĵ�ַ 

void RemoveFrontRearBlank(char *&str){
	if(!str)
		return;
	char *start = str;
	char *end = str + strlen(str) - 1;
	while(' ' == *start)
		++start;
	if(end - start < 0){
		*str = '\0';
		return;
	}
	while(' ' == *end)
		--end;
	char *front = str;
	while(end >= start)
		*front++ = *start++;
	*front = '\0';//����Ҳ������� 
}
/* ��������Ҳ������Ҫ */
void TestRemoveFrontRearBlank(){
	const int size = 8;
	char **str = new char*[size];
	for(int i = 1; i < size; ++i)
		str[i] = new char[100];
	str[0] = NULL;
	strcpy(str[1], "");
	strcpy(str[2], "a");
	strcpy(str[3], " a");
	strcpy(str[4], "a ");
	strcpy(str[5], " a ");
	strcpy(str[6], "  a  b  c  ");
	strcpy(str[7], "      ");//���������������Ҫ�������Թٽ����ȫ�ǿո��Ӧ����ô����Ӧ�ô���� \0
	for(int i = 1; i < size; ++i){
		cout<<str[i]<<endl;
		cout<<"len = "<<strlen(str[i])<<endl;
		RemoveFrontRearBlank(str[i]);
		cout<<str[i]<<endl;
		cout<<"len = "<<strlen(str[i])<<endl;
		delete[] str[i];//���new��һ��Ҫ�Լ�delete 
		cout<<"---------------------"<<endl;
	}
	delete[] str;
}
int main(){
	TestRemoveFrontRearBlank();
}
