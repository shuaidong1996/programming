#include <queue>
#include <iostream>
#include <stack>
using namespace std;
template<class _Ty>
const _Ty & Max(const _Ty &a, const _Ty &b)
{
	return a>b ? a : b;
}
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

/*�ж���ȫ������*/
bool Is_Comp_BinaryTree(BtNode *p)
{
	queue<BtNode *> q;
	q.push(p);
	bool tag = 0;//���ڱ�ʶ�Ƿ���ֵ�һ���պ��ӣ����ֿպ󣬲����ٳ��ֲ�Ϊ�յĽڵ�
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->leftchild != NULL){
			if (tag)
				return false;
			q.push(p->leftchild);
		}
		else
			tag = 1;
		if (p->rightchild != NULL){
			if (tag)
				return false;
			q.push(p->rightchild);
		}
		else
			tag = 1;
	}
	return true;
}
/*
�ж���������  ������Ҳû���ҵ�����Ĵ��룬�Լ����
����1:������߶Ⱥͽڵ�������������  2^�߶� - 1 = �ڵ���
����2:�����´���  ���õ�������ȵ�˼��
����3:�ǵݹ飬ÿһ���һ����ǣ�ҪôȫΪNULL��Ҫôȫ��ΪNULL
*/
int isEqualHight_sys(BinaryTree root,bool &tag)
{
	if (!root) return 0;
	int leftHeight = isEqualHight_sys(root->leftchild, tag);
	int rightHeight = isEqualHight_sys(root->rightchild, tag);
	if (leftHeight != rightHeight)
		tag = true;
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
bool isEqualHight(BinaryTree root)
{
	bool tag = false;//�����������˱�־λ��ֻҪ��һ�β��ȸ���ô�Ҿ��޸ı�־λ���Ͳ���������������bug��
	isEqualHight_sys(root, tag);
	if (tag) return false;
	return true;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int getDepth(BinaryTree root)
{
	if (!root) return 0;
	return max(getDepth(root->leftchild), getDepth(root->rightchild)) + 1;//����������������������ߵģ�Ȼ�� + 1������
}
bool isEqualHight2(BinaryTree root)
{
	return (root == NULL || 
		getDepth(root->leftchild) == getDepth(root->rightchild) && 
		isEqualHight2(root->leftchild) && isEqualHight2(root->rightchild));
}
/*�ж�ƽ�������*/
/*�ʼ������������д�ģ������������������⣬���������߲��ȸߣ�but��߳������β��ȸߣ���ô�ͻ����false = false ������߾ͱ����true == �ұ�true*/
//bool isEqualHight(BinaryTree root)
//{
//	if (!root) return true;
//	int leftHeight = isEqualHight(root->leftchild);
//	int rightHeight = isEqualHight(root->rightchild);
//	if (leftHeight != rightHeight)//����������߶Ȳ���������������ô�߶ȼ�1
//		return false;
//	return true;
//}
/*����������Ȳ�����1*/
bool IsBalanced(BinaryTree root)
{
	if (!root)
		return true;
	int leftDepth = getDepth(root->leftchild);
	int rightDepth = getDepth(root->rightchild);
	int diff = leftDepth - rightDepth;
	if (diff > 1 || diff < -1)
		return false;
	return IsBalanced(root->leftchild) && IsBalanced(root->rightchild);
}
/*������������ܶ���η����ߣ����ǿ��Ժ�������������棬Ȼ��Ѹ߶ȼ�¼����*/
bool IsBalanced2(BinaryTree root,int &depth)
{
	if (!root)
		return true;
	int leftDepth, rightDepth;
	//�ȵ�������
	if (IsBalanced2(root, leftDepth) && IsBalanced2(root, rightDepth)){
		//�ж��Ƿ�߶Ȳ�1
		int diff = leftDepth - rightDepth;
		if (diff >= -1 || diff <= 1){
			depth = (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;//�߶ȼ�1����Ϊ�����ã��᷵�ظ���һ��
			return true;
		}
	}
	return false;
}
bool IsBalanced2(BinaryTree root)
{
	int dep = 0;
	return IsBalanced2(root,dep);
}
///////////////////////////////////////////////////////
void prePrint(BinaryTree root)
{
	if (root)
	{
		cout << root->data << "\t";
		prePrint(root->leftchild);
		prePrint(root->rightchild);
	}
}
void main()
{
	ElemType *str1 = "ABDH###E##CF##G##";
	ElemType *str2 = "ABDH###E1###CF##G##";
	ElemType *str3 = "ABD##E##CF##G##";
	ElemType *str4 = "ABDH##J##E##CF##G##";
	BinaryTree root = CreateTree2(str1);
	prePrint(root);
	cout << endl << "str1 ��ȫ��������" << Is_Comp_BinaryTree(root) << endl;
	cout << endl << "--------------------------------" << endl;

	BinaryTree root2 = CreateTree2(str2);
	prePrint(root2);
	cout << endl << "str2 ��ȫ��������" << Is_Comp_BinaryTree(root2) << endl;
	cout << endl << "--------------------------------" << endl;

	BinaryTree root3 = CreateTree2(str3);
	prePrint(root3);
	cout << endl << "str3 ����������" << isEqualHight(root3) << endl;
	cout << endl << "str3 ��������2��" << isEqualHight2(root3) << endl;
	cout << endl << "--------------------------------" << endl;

	BinaryTree root4 = CreateTree2(str4);
	prePrint(root4);
	cout << endl << "str4 ����������" << isEqualHight(root4) << endl;
	cout << endl << "str4 ��������2��" << isEqualHight2(root4) << endl;
	cout << endl << "--------------------------------" << endl;

	system("pause");
}