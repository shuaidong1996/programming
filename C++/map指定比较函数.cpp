#include <iostream>
#include <map> 
#include <string>
using namespace std;

//��ʵ greater<int>() ����һ���º������� 

class MyCompare{
public:
	bool operator()(const string &s1, const string &s2){
		if (s1.length() < s2.length())
			return false;
		else if (s1.length() > s2.length())
			return true;
		else{
			return s1 < s2;
		}
	}
};
void test(){
	map<string, int, MyCompare> mp;
	mp["d"] = 1;
	mp["chen"] = 1;
	mp["ming"] = 1;
	mp["shuai"] = 1;
	for (auto m : mp){
		cout << m.first << " -> " << m.second << endl;
	}
}
/////////////����<Ҳ����/////////////////////////////
class Dong{
public:
	int a;
	string str;
	Dong(int a, string str) :a(a), str(str){}
	bool operator< (const Dong &d) const{//����const����ʡ�ԣ����õ�ʱ���ǵ���const����
		return a < d.a;
	}
};
void test2(){
	map<Dong, int> mp;
	mp[Dong(2,"ming")] = 1;
	mp[Dong(3, "dong")] = 1;
	mp[Dong(1, "chen")] = 1;
	++mp[Dong(3, "dong")];
	for (auto m : mp){
		cout << m.first.str << " -> " << m.second << endl;
	}
}
int main(){
	test();
	cout << "--------------" << endl;
	test2();
}
