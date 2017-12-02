/*
���1. �ڵ�ֻ��left/right��û��parentָ�룬root��֪

���2. rootδ֪������ÿ���ڵ㶼��parentָ��

���3. �������Ǹ��������������root�������ڵ��ֵ(a, b)��֪


1.������ַ�����1���ҵ�ĳ���ڵ㣬Ȼ���Ҹ��ڵ㣨�����δ��뵽�����У���Ȼ����һ���ڵ�Ҳ�����Ҹ��ڵ㣨ÿ��һ�ξͱ���һ���������Ƿ���������ڵ㣩
			��2������һ�漰����ѭ�������ǿ������ҵ��������ڵ㣬Ȼ�������Ҹ��ڵ㣬�������ڵ��ڸ��ڵ���ұ߾���string�� + "1" ��߾� + "0" ��ʱ������ʼ�Ƚ������ַ�����ʲôʱ����ȣ��Ǿ��ǹ������ڵ�
			��3������2�Ǵ����3�еõ�����У��Ӹ���ʼ������������ڵ��ڸ������ߣ�˵��������ǹ����ڵ㣬�������
			��4���ҵ������ڵ��·����Ȼ����������������Ľڵ㣬���ǹ������ڵ�

2.˼·���ӵ�ǰ�ڵ㵽root�γ�������������Ҫ��ľ������������һ�������ڵ�

3.ֻҪ�ӽڵ���ֵ�ڸ�����ֵ�����ߣ���ô������ǹ������ڵ㣨��򵥵ģ�
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef char ElemType;
#define  END '#'

typedef struct BtNode  // BinaryTreeNode
{
	//BtNode *parent;
	BtNode *rightchild;
	BtNode *leftchild;
	ElemType data;
}BtNode, *BinaryTree;

BtNode * _Buynode()
{
	BtNode *s = (BtNode*)malloc(sizeof(BtNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(BtNode));
	return s;
}

BtNode * CreateTree2(ElemType *&str)
{
	BtNode *s = NULL;
	if (*str != END)
	{
		s = _Buynode();
		s->data = *str;
		s->leftchild = CreateTree2(++str);
		s->rightchild = CreateTree2(++str);
	}
	return s;
}
/* û�д���û�ҵ��������Ҳ���ǲ����Ҹ�һ���ڵ���Ϣ  ���ǽ��������һ������һ�����ڵ����� */
//�Ӹ���ʼ������������ڵ��ڸ������ߣ�˵��������ǹ����ڵ㣬�������
BinaryTree findLowestParrent(BinaryTree root, BinaryTree a, BinaryTree b){
	if (root == NULL)
		return NULL;
	if (root == a || root == b)//ֻҪ�ҵ�һ���ڵ�ͷ�������ڵ�
		return root;
	BinaryTree left = findLowestParrent(root->leftchild, a, b);
	BinaryTree right = findLowestParrent(root->rightchild, a, b);
	if (left != NULL && right != NULL)//�����ҽڵ㶼��Ϊ�յ�ʱ��˵���ҵ�������Ĺ������ڵ㣬���õĻ������3��˼·���Ӹ��ڵ�һ�£�ֻҪĳ���ڵ���������������Ҫ�ҵĽڵ㣬˵������������ǵĹ������ڵ㣩
		return root;
	return left != NULL ? left : right;//�������нڵ㣬������ߡ���Ҳ����������ڵ㶼����ߵ������һ���ڵ�����һ���ĸ��ڵ㣩���ص���Ȼ��������ڵ�
}
/*����˲����ڵĽڵ�����  ���ұ��ͨ�ã������˼·Ҳ������*/
//�ҵ������ڵ��·����Ȼ����������������Ľڵ㣬���ǹ������ڵ�
bool findPath(BinaryTree root, BinaryTree a, vector<BinaryTree> &v){
	if (!root || !a)
		return false;
	if (root == a){		//�ҵ���
		v.push_back(root);
		return true;
	}
	v.push_back(root);
	bool res = false;
	if (root->leftchild)//ȥ�����
		res = findPath(root->leftchild, a, v);
	if (!res && root->rightchild)//������û���ҵ���ȥ�ұ�
		res = findPath(root->rightchild, a, v);
	if (!res)//�ұ�Ҳû�ҵ�
		v.pop_back();
	return res;
}
BinaryTree findLowestParrent2(BinaryTree root, BinaryTree a, BinaryTree b){
	vector<BinaryTree> v1;
	vector<BinaryTree> v2;
	findPath(root, a, v1);
	findPath(root, b, v2);
	int len = v1.size() < v2.size() ? v1.size() : v2.size();
	for (int i = len - 1; i >= 0; --i){
		if (v1[i] == v2[i])
			return v1[i];
	}
	return NULL;
}
/*-----------------------����Ĵ�����ǲ�����---------------------------*/
BinaryTree findNode(BinaryTree root, char ch)
{
	BinaryTree tree = NULL;
	if (root != NULL)
	{
		if (ch == root->data)
			return root;
		tree = findNode(root->leftchild, ch);
		if (tree == NULL)
			tree = findNode(root->rightchild, ch);
	}
	return tree;
}
void test1(){
	cout << "----------------����1-----------------------" << endl;
	ElemType *str1 = "ABDH##J##E##CF##G##";
	BinaryTree root = CreateTree2(str1);
	BinaryTree a = findNode(root, 'H');
	BinaryTree b = findNode(root, 'J');
	cout << a->data << endl;
	cout << b->data << endl;
	cout << findLowestParrent(root, a, b)->data << endl;

	cout << "---------------------------------------" << endl;
	BinaryTree a2 = findNode(root, 'B');
	BinaryTree b2 = findNode(root, 'E');
	cout << a2->data << endl;
	cout << b2->data << endl;
	cout << findLowestParrent(root, a2, b2)->data << endl;

	cout << "----------------��һ��û�ҵ������-----------------------" << endl;
	BinaryTree a3 = new BtNode;
	a3->data = 'M';
	a3->leftchild = a3->rightchild = NULL;
	BinaryTree c3 = findLowestParrent(root, a3, b2);//a3�������棬�������Ƿ�����b2����Ϊb2����
	if (c3)
		cout << c3->data << endl;
	else
		cout << "û�ҵ�" << endl;
}
void test2(){
	cout << "----------------����2-----------------------" << endl;
	ElemType *str1 = "ABDH##J##E##CF##G##";
	BinaryTree root = CreateTree2(str1);
	BinaryTree a = findNode(root, 'H');
	BinaryTree b = findNode(root, 'J');
	cout << a->data << endl;
	cout << b->data << endl;
	cout << findLowestParrent2(root, a, b)->data << endl;

	cout << "---------------------------------------" << endl;
	BinaryTree a2 = findNode(root, 'B');
	BinaryTree b2 = findNode(root, 'E');
	cout << a2->data << endl;
	cout << b2->data << endl;
	cout << findLowestParrent2(root, a2, b2)->data << endl;

	cout << "----------------��һ��û�ҵ������-----------------------" << endl;
	BinaryTree a3 = new BtNode;
	a3->data = 'M';
	a3->leftchild = a3->rightchild = NULL;
	BinaryTree c3 = findLowestParrent2(root, a3, b2);//a3�������棬�������Ƿ�����b2����Ϊb2����
	if (c3)
		cout << c3->data << endl;
	else
		cout << "û�ҵ�" << endl;
}
int main()
{
	test1();
	test2();
	system("pause");
}
/*								������Ҷ���������
										A
								B				C
							D		E		F		G
						  H   J
*/