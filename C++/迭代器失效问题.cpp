#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
using namespace std;
/* ���� ɾ�� ������ʧЧ���� */
template<typename T>
void print(T t){
	for(auto it = t.begin(); it != t.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;
}
void testVec(){
	vector<int> v(4);
	cout<<"ԭ����"<<endl;
	print(v);
	cout<<"����Ԫ��6"<<endl;
	for(auto it = v.begin(); it != v.end(); ++it){
		if(0 == *it){
			it = v.insert(it, 6);//��������ʧЧ ����ֵ�ǵ�ǰ�����Ԫ��  ע�⣺��������itǰ�� ����Ҫ++���� 
			++it;
		}
	}
	print(v);
	cout<<"ɾ��Ԫ��0"<<endl;
	for(auto it = v.begin(); it != v.end();){
		if(0 == *it)
			it = v.erase(it);//ʧЧ itָ��ɾ��Ԫ�� ������һ��Ԫ�� 
		else
			++it;
	}
	print(v);
}
void testList(){
	list<int> l(4);
	cout<<"ԭlist"<<endl;
	print(l);
	cout<<"����Ԫ��6"<<endl;
	for(auto it = l.begin(); it != l.end(); ++it){
		if(0 == *it)
			l.insert(it, 6);//��������ʧЧ itָ��ԭ����Ԫ�� 
	}
	print(l);
	cout<<"ɾ��Ԫ��0"<<endl;
	for(auto it = l.begin(); it != l.end();){
		if(0 == *it)
			it = l.erase(it);//ʧЧ itָ��ɾ��Ԫ�� ������һ��Ԫ�� 
		else
			++it;
	}
	print(l);
	cout<<"ɾ��Ԫ��6"<<endl;
	for(auto it = l.begin(); it != l.end();){
		if(6 == *it)
			l.erase(it++);//ʧЧ it��ǰ������һ��Ԫ��  ֻ�еײ�������ṹ���� 
		else
			++it;
	}
	print(l);
}
void testDeque(){
	deque<int> d(4);
	cout<<"ԭdeque"<<endl;
	print(d);
	cout<<"����Ԫ��6"<<endl;
	for(auto it = d.begin(); it != d.end(); ++it){
		if(0 == *it){
			it = d.insert(it, 6);//��������ʧЧ ����ֵ�ǵ�ǰ�����Ԫ��  ע�⣺��������itǰ�� ����Ҫ++���� 
			++it;
		}
	}
	print(d);
	cout<<"ɾ��Ԫ��0"<<endl;
	for(auto it = d.begin(); it != d.end();){
		if(0 == *it)
			it = d.erase(it);//ʧЧ itָ��ɾ��Ԫ�� ������һ��Ԫ�� 
		else
			++it;
	}
	print(d);
}
void testSet(){
	set<int> s;
	for(int i = 0; i < 3; ++i)
		s.insert(i);
	cout<<"ԭset"<<endl;
	print(s);
	cout<<"����Ԫ��6 ������ָ��->";
	for(auto it = s.begin(); it != s.end(); ++it){
		if(1 == *it){
			s.insert(it, 6);//��������ʧЧ itָ��ǰԪ��  
			cout<<*it<<endl;
		}
	}
	print(s);
	cout<<"ɾ��Ԫ��6"<<endl;
	for(auto it = s.begin(); it != s.end();){
		if(6 == *it)
			it = s.erase(it);//ʧЧ itָ��ɾ��Ԫ�� ������һ��Ԫ�� 
		else
			++it;
	}
	print(s);
	cout<<"ɾ��Ԫ��1"<<endl;
	for(auto it = s.begin(); it != s.end();){
		if(1 == *it)
			s.erase(it++);//ʧЧ it��ǰ������һ��Ԫ��  ֻ�еײ�������ṹ���� 
		else
			++it;
	}
	print(s);
}
template<typename T>
void printMap(T t){
	for(auto it = t.begin(); it != t.end(); ++it)
		cout<<"["<<it->first<<"]"<<it->second<<"\t";
	cout<<endl;
}
void testMap(){
	map<int, int> m;
	m[1] = 10;
	m[2] = 20;
	m[3] = 30;
	printMap(m);
	cout<<"����key6"<<endl;
	/* ��ȫû�б�ҪŪһ��ѭ�� ��Ϊ�ײ㶼�Ǻ������ʽ ��ǰ���������Ķ�����ν ֻ��Ϊ��˵��insert��������ʧЧ
		insert(it, 6) �ײ������insert(6) 
	 */
	for(auto it = m.begin(); it != m.end(); ++it){
		if(2 == it->first)
			m.insert(it, pair<int, int>(6, 60));//insert��Ч�ʱȡ�����
	}
	printMap(m);
	cout<<"ɾ��key6"<<endl;
	for(auto it = m.begin(); it != m.end();){
		if(6 == it->first)
			m.erase(it++);//ʧЧ it��ǰ������һ��Ԫ��  ֻ�еײ�������ṹ���� 
		else
			++it;
	}
	printMap(m);
}
int main(){
	cout<<"------------vector------------"<<endl;
	testVec();
	cout<<"-------------list-----------"<<endl;
	testList(); 
	cout<<"-------------Deque-----------"<<endl;
	testDeque();
	cout<<"--------------Set----------"<<endl;
	testSet();
	cout<<"--------------Map----------"<<endl;
	testMap();
}
/*
�ܽ᣺
vector:�����ɾ��Ԫ�ض���ʹ������ʧЧ
deque:�����ɾ��Ԫ�ض���ʹ������ʧЧ
list:���룬����������ʧЧ��ɾ����ָ��ɾ���ڵ������ʧЧ
set:���룬����������ʧЧ��ɾ����ָ��ɾ���ڵ������ʧЧ
map:���룬����������ʧЧ��ɾ����ָ��ɾ���ڵ������ʧЧ
*/ 
