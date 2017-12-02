#include <iostream>
#include <stack>
using namespace std;

typedef struct Node
{
	char val;
	Node *left,*right;
}Node;
Node *Create(char *&str)
{
	if(!str || !*str || '#' == *str)
		return NULL;
	Node *node = new Node;
	node->val = *str;
	node->left = Create(++str);
	node->right = Create(++str);
	return node;
}
//�ݹ�---�������������˼��
void Mirror(Node *node){
	if(!node)
		return;
	Node *temp = node->left;
	node->left = node->right;
	node->right = temp;
	Mirror(node->left);
	Mirror(node->right); 
}
//�ǵݹ�---���ò�α�����˼��
void Mirror2(Node *node){
	if(!node)
		return;
	stack<Node *> s;
	s.push(node);
	while(!s.empty()){
		node = s.top();
		s.pop();
		Node *l = node->left,*r = node->right;//����������������λ�� 
		node->left = r;
		node->right = l;
		if(l) s.push(l);
		if(r) s.push(r);//ע�⣺ �������if����д�� else if  ��Ū��һ�� 
	}
}
/////////////////////����/////////////////////
void print(Node *node)
{
	if(node){
		cout<<node->val<<" ";
		print(node->left);
		print(node->right);
	}
}
void test1(){
	char *str1 = "123##4##2324##3###6##";
	Node *node1 = Create(str1);
	print(node1);
	cout<<endl<<"--------------------------"<<endl;
	Mirror(node1);
	print(node1);
}
void test2(){
	char *str1 = "123##4##2324##3###6##";
	Node *node1 = Create(str1);
	cout<<endl<<"--------------------------"<<endl;
	Mirror2(node1);
	print(node1);
}
int main(){
	test1();
	test2();
}
