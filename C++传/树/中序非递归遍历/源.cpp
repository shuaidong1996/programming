#include "Tree.h"
void createTree(Tree &t, char a[], int &i)//ע���������Ǳ�����&���ã���Ϊ����Ҫ�ı䴫������root�ĵ�ַ��ҪΪ�������ڴ棩
{
	if (i > 9 || a[i] == ' ')
	{
		t = NULL;
		return;
	}
	cout << a[i] << "+++" << endl;

	t = new Node(a[i]);
	createTree(t->left, a, ++i);
	createTree(t->right, a, ++i);
}
//�ݹ��������
void inOrderY(Tree t)
{
	if (!t)
		return;
	inOrderY(t->left);
	cout << t->val << "   ";
	inOrderY(t->right);
}
//�ݹ��������
void preOrderY(Tree t)
{
	if (!t)
		return;
	cout << t->val << "   ";
	preOrderY(t->left);
	preOrderY(t->right);
}
//�ݹ�������
void postOrderY(Tree t)
{
	if (!t)
		return;
	postOrderY(t->left);
	postOrderY(t->right);
	cout << t->val << "   ";
}
