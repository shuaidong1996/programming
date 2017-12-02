#include <iostream> 
#include <hash_map>
#include <string>
using namespace std;

void test1(){
	__gnu_cxx::hash_map<int, string> hm;//windows�������� std�����ռ��� 
	hm[4] = "˧";
	hm[2] = "˧";
	hm[3] = "��";
	for(auto h : hm){
		cout<<h.first<<"->"<<h.second<<endl;
	}
}
/*
2->˧
3->��
4->˧
*/ 
/*
hash_mapģ����� 
template <class Key, class T, class HashFcn = hash<Key>,
          class EqualKey = equal_to<Key>,
          class Alloc = alloc>
hashtableģ�������
template <class Value, class Key, class HashFcn,
          class ExtractKey, class EqualKey,
          class Alloc>

typedef hashtable<pair<const Key, T>, Key, HashFcn,
            select1st<pair<const Key, T> >, EqualKey, Alloc> ht;
    
���õ�HashFcn��
struct hash<char*>
struct hash<const char*>
struct hash<char> 
struct hash<unsigned char> 
struct hash<signed char>
struct hash<short>
struct hash<unsigned short> 
struct hash<int> 
struct hash<unsigned int>
struct hash<long> 
struct hash<unsigned long> 
����key�Ƚϣ� 
struct equal_to : public binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const { return x == y; }
};

ע��hash_map<int, string> �ȼ��� hash_map<int, string, hash<int>, equal_to<int>, alloc> 
select1st ������ȡkey��  mapҲ���õ�select1st
 
�������û�����õ�hashFcn����Ҫ�Լ�дһ��  
*/ 

//
namespace __gnu_cxx{
	template<>
	struct hash<string>{
		size_t operator()(const string &s) const { return __stl_hash_string(s.c_str()); }
		//size_t operator()(const string &s) const { return hash<const char*>()(s.c_str()); }//���Ҳ�� ����ע��ģ����Ҫʵ�������ܵ���() 
	};
}
/* __stl_hash_string Ϊstl�ں� const char *��hash���� 
inline size_t __stl_hash_string(const char* s){
  unsigned long h = 0; 
  for ( ; *s; ++s)
    h = 5*h + *s;
  return size_t(h);
}
struct hash<const char*>{
  size_t operator()(const char* s) const { return __stl_hash_string(s); }
};
*/
/* key = string, value = int */ 
void test2(){
	__gnu_cxx::hash_map<string, int> hm;
	++hm["˧"];
	++hm["��"];
	++hm["˧"];
	for(auto h : hm){
		cout<<h.first<<"->"<<h.second<<endl;
	}
}
/*
��->1
˧->2
*/ 
/* ����������̫�ã��Ͼ�̫ǣ��ײ��� */
class HashString{
public:
	size_t operator()(const string &s) const {
		return __gnu_cxx::__stl_hash_string(s.c_str());
	}
}; 
void test3(){
	__gnu_cxx::hash_map<string, int, HashString> hm;
	++hm["˧"];
	++hm["��"];
	++hm["˧"];
	for(auto h : hm){
		cout<<h.first<<"->"<<h.second<<endl;
	}
}

/* �Ƚ�Ͱ�ڵ����ݺ�key�Ƿ���� */
/* ���壺�п���������ͬ��key��Ӧͬһ��Ͱ ��ʱ�����Ҫ�ȽϺ��� �Ƿ���Ҫ�����µ�key */
/* ���ڵ������ǣ����Դ�Сд����key�Ƚ� */ 
/* ������Ҫ�޸�equal��hash����Ҳ�ø� */
class HashString2{
public:
	size_t operator()(const string &s) const {
		/* ���Դ�Сдhash->ȫ������Сд����hash */ 
		int num = 0, size = s.size();
		while(size--) {
			num = 5 * num + s[size];
			if(s[size] < 'a')
				num += 'a' - 'A';
		} 
		return num; 
	}
}; 
class MyStringEqual {
public:
    bool operator()(const string &x, const string &y) const {
		int size = x.size();
		if(size != y.size())
			return false;
		cout<<x<<" compare to "<<y<<endl;
		int diff = 'a' - 'A';
		while(size--){
			if(x[size] != y[size] && 
			x[size] - diff != y[size] &&
			x[size] + diff != y[size])
				return false;
		}
		return true;
	}
};
void test4(){
	__gnu_cxx::hash_map<string, int, HashString2, MyStringEqual> hm;
	++hm["shuai"];//���û�г�ʼ��Ϊ0 ++���Ϊ 1 
	++hm["dong"];
	++hm["Dong"];//Dong hash�����"dong"  һ������ô�ͻ����equal�������������Ƚ���������ַ������ "Dong"���key ��������ô��������"Dong" 
	++hm["DONG"];
	++hm["SHUai"];
	for(auto h : hm){
		cout<<h.first<<"->"<<h.second<<endl;
	}
}
/*
dong compare to Dong
dong compare to DONG
shuai compare to SHUai
shuai->2
dong->3
*/ 
int main(){
//	test1();
//	test2();
//	test3();
	test4();
}
