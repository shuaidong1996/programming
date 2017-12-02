#include <iostream>
#include <map>
#include <string> 
using namespace std;

void WorldCount(string str){
	if (str.empty())
		return;
	auto start = str.begin();
	auto end = start;
	map<string, int> m;
	while (end != str.end()){
		//ע�⣺�ڲ�ҲҪ�ж��Ƿ����  �� ����һ��
		while (start != str.end() && (*start == ' ' || *start == '\n' || *start == '\t'))
			++start;
		end = start; 
		while (end != str.end() && *end != ' ' && *end != '\n' && *end != '\t')
			++end;
		if (start == str.end())//Ϊʲô��start ���� end ���� ��Ϊ���һ���ַ�����ӡ������ 
			break;
		string s(start, end);
		if (m.find(s) == m.end())
			m[s] = 1;
		else
			++m[s];
		start = end;
	}
	for (auto it = m.begin(); it != m.end(); ++it)
		cout << it->first << ":" << it->second << endl;
}

int main() {
	string str("  chen ming dong \
hello dong nice to meet you!! \
chen ming dong  ");
	WorldCount(str);
}
