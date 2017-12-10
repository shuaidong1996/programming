#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	Node *next;
	Node(int val) :val(val){ next = NULL; }
};
//ע�⽻�����������ֽ���ֻ��������
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
Node *SplitByMid(Node *left, Node *right){
	if(!left)
		return left;
	int axis = left->val;//axisΪ����
	/* l��r֮��������Ǳ�axis�������lָ�����С�ڵ���axis���� */
	Node *l = left;
	Node *r = l->next;
	while (r != right){
		if (r->val < axis){
			l = l->next;//����Ҫ����ָ����һ���ٽ�������һ��Ҫô�Ǵ���axis�ģ�Ҫô�������������
			swap(l->val, r->val);
		}
		r = r->next;
	}
	swap(l->val, left->val);//��������ָ����һ���ٽ��������Ե�һ��û�б����� 
	return l;
}
void QuickSortList(Node *l, Node *r){
	if (l != r){
		Node *mid = SplitByMid(l, r);
		QuickSortList(l, mid);
		QuickSortList(mid->next, r);//һ��Ҫ��next��Ȼ����ѭ��
	}
}
void print(Node *head){
	if (head != NULL){
		cout << head->val << " ";
		print(head->next);
	}
}
/* ���� */
void test1(){
	int arr[] = { 5, 6, 7, 1, 2, 9, 3, 4, 8, 4, 5, 2 };
	int len = sizeof(arr) / sizeof(int);
	Node *head = new Node(arr[0]);
	Node *temp = head;
	for (int i = 1; i < len; ++i){
		Node *n = new Node(arr[i]);
		temp->next = n;
		temp = n;
	}
	print(head);
	cout << endl;
	QuickSortList(head, NULL);
	print(head);
	cout << endl;
} 
void test2(){
	int arr[] = { 5 };
	int len = sizeof(arr) / sizeof(int);
	Node *head = new Node(arr[0]);
	Node *temp = head;
	for (int i = 1; i < len; ++i){
		Node *n = new Node(arr[i]);
		temp->next = n;
		temp = n;
	}
	print(head);
	cout << endl;
	QuickSortList(head, NULL);
	print(head);
} 
int main(){
	test1(); 
	test2();
}
