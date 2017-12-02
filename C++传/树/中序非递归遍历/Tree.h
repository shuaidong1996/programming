#ifndef TREE
#define TREE
#include <iostream>
using namespace std;
typedef struct NODE{
	char val;
	struct NODE *left, *right;
	NODE(int val) :val(val), left(NULL), right(NULL){}
}Node, *Tree;

void createTree(Tree &t, char a[], int &i);
//�ݹ��������
void inOrderY(Tree t);
//�ݹ��������
void preOrderY(Tree t);
//�ݹ�������
void postOrderY(Tree t);
#endif