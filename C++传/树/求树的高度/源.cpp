#include <iostream>
#include <algorithm>
#include <queue>
#include "tree.h"
using namespace std;

void create(Tree &p, int val)
{
	if (p == NULL)
		p = new Node(val);
	else{
		if (val < p->val)
			create(p->left, val);
		if (val > p->val)
			create(p->right, val);
	}
}
//�ݹ�
int getDepth(Tree root){
	if (!root) return 0;
	return max(getDepth(root->left), getDepth(root->right)) + 1;//����������������������ߵģ�Ȼ�� + 1������
}
//�ǵݹ�
int getDepth2(Tree root){
	if (!root)	
		return 0;
	queue<Node *> q;
	q.push(root);
	int dep = 0;
	while (!q.empty()){
		int size = q.size();
		++dep;
		while (size--){
			Node *node = q.front();
			q.pop();
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	return dep;
}
int main()
{
	int a[20];
	Tree root = NULL;
	//�ȴ���һ���� 
	for (int i = 0; i<10; i++){
		a[i] = rand() % 100;
		printf("%-5d", a[i]);
	}
	for (int i = 0; i<10; i++)
		create(root, a[i]);

	cout << endl;
	//���������� 
	cout << "���߶�" << getDepth(root) << endl;
	cout << "���߶�" << getDepth2(root) << endl;

	cin.get();
	return 0;
}
