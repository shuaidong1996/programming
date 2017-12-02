#include <iostream>
#include <cstdlib>
#include <stack>
#include "Tree.h"
using namespace std;

//�ǵݹ��������
void inOrder(Tree t)
{
	stack<Tree> stackTree;
	Tree p = t;
	if (!t)
	{
		cout << "����һ������" << endl;
	}
	//����Ĵ���Ƚ��������ٶȣ�
	while (t || !stackTree.empty())
	{
		while (t)				//��������������ڣ��Ƚϵ����Լ����������Լ���left����
		{
			stackTree.push(t);//ֻҪ�Լ����ڣ�����ջ
			t = t->left;	//Ȼ���ٱ���������
		}
		//���ڵ�t��NULL��
		t = stackTree.top();//���Ȼ�ȡ���ڵ�
		stackTree.pop();	//������ջ
		printf("%c   ", t->val);//��ӡ���ֵ
		t = t->right;		//��������ڵ�������������ô����ھ���right�ǿգ���һ��ѭ�����ǻ�ȡջ�еĸ��ڵ㣬��Ϊ����ջ������
	}

	cout << endl << "����2" << endl;
	while (!stackTree.empty() || p)
	{
		if (p)//��Ϊ�վ���ջ����ָ��������
		{
			stackTree.push(p);
			p = p->left;
		}
		else//Ϊ�վ� ȡ��ջ�� Ԫ�أ���ָ��������
		{
			p = stackTree.top();
			stackTree.pop();
			cout << p->val << "   ";
			p = p->right;
		}
	}
}

//�ǵݹ��������
void preOrder(Tree t)
{
	if (t == NULL)
		return;
	stack<Tree> stackTree;
	Tree p = t;

	/*��һ�ַ��������������ｨ�鿴���֡�����*/
	while (t || !stackTree.empty())
	{
		while (t)
		{
			stackTree.push(t);//ֻҪ�Լ����ڣ�����ջ
			printf("%c   ", t->val);//��ӡ���ֵ
			t = t->left;	//Ȼ���ٱ���������
		}
		//���ڵ�t��NULL��
		t = stackTree.top();//���Ȼ�ȡ���ڵ�
		stackTree.pop();	//������ջ
		t = t->right;		//��������ڵ�������������ô����ھ���right�ǿգ���һ��ѭ�����ǻ�ȡջ�еĸ��ڵ㣬��Ϊ����ջ������
	}
	cout << endl << "����2" << endl;

	//����2 ����ֻ��Ҫһ��ѭ��
	while (!stackTree.empty() || p)
	{
		if (p)//��Ϊ�վ���ջ������ӡ
		{
			cout << p->val << "   ";
			stackTree.push(p);
			p = p->left;
		}
		else//Ϊ�վ� ȡ��ջ�� Ԫ�أ����������Ԫ�ص� ������
		{
			p = stackTree.top();
			stackTree.pop();
			p = p->right;
		}
	}
}

//�ǵݹ�������   �����ⷽ�����鲻Ҫ������Ϊ�����ָ���������
void postOrder(Tree t)
{
	if (!t)
		return;
	stack<Tree> s;
	//pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ�
	Tree pCur, pLastVisit = NULL;
	pCur = t;


	//�Ȱ�pCur�ƶ�������λ��
	while (pCur)								//�������ǲ���1
	{
		s.push(pCur);
		pCur = pCur->left;
	}
	while (!s.empty())//ֻҪջ��Ϊ����ôһ�����ڵ�һ�����ڵ㣬����Ϊ��Ϊ����Ϊ�ж��Ƿ�ȫ������������
	{
		pCur = s.top();//��ȡ���ڵ�
		s.pop();
		//�����ж��Ƿ���Է����Һ��ӣ���Ϊֻ�в��ܷ����ҽڵ��ʱ��Ŵ�ӡ����������������Ҹ��ı�����
		if (!pCur->right || pCur->right == pLastVisit)//��������������  ���� �Ѿ������ʹ�  ��ô˵�����ҷ����Ѿ����������Դ�ӡ��
		{
			cout << pCur->val << "   ";
			//�޸���������ʵĽڵ�
			pLastVisit = pCur;
		}
		else//������ܴ�ӡ  ��ô������һ�����Է���
		{
			s.push(pCur);//��������Һ��� ��ô����ջ
			pCur = pCur->right;//��������ڵ���Һ���

			while (pCur)//ֻҪ�Һ��Ӽ�����������������   //����Ҳ���ǲ���1  ������һ����������ѭ�����㲽��2
			{
				s.push(pCur);
				pCur = pCur->left;
			}
		}
	}
}
/*��ס�ڶ��ַ�ʽ���ͷǵݹ���������ǳ�����Ҫ��һ���жϣ��жϵ�ǰ���ڵ���Һ����Ƿ�Ϊ�ջ����Ƿ񱻷���*/
void postOrder2(Tree t)
{
	if (t == NULL)
		return;
	stack<Tree> stackTree;
	Tree pLastVisit = NULL;

	while (t || !stackTree.empty())
	{
		while (t)
		{
			stackTree.push(t);
			t = t->left;
		}
		t = stackTree.top();
		stackTree.pop();
		if (!t->right || t->right == pLastVisit)
		{
			printf("%c   ", t->val);
			pLastVisit = t;
			t = NULL;								//************��һ����Ӳ��û�뵽��������
		}
		else
		{
			stackTree.push(t);
			t = t->right;
		}
	}
}

/*
������������ѵģ���Ϊ�������ȷ������ӣ�Ȼ������Һ��ӣ����ŷ��ʸ���������Ѿ����ʹ��ˣ�
1.���ӵķ������ֱ��һֱѭ����û������Ϊֹ
2.Ȼ���ȡ�Һ���
�����Һ��ӵ�ʱ�򣬾ͻ��һ�����裺ÿ�η��ʸ���ʱ����Ҫ�ж��Һ����Ƿ��� �� �Ƿ��Ѿ������ʣ���������������ϣ����ܴ�ӡ����(û�з��������1 2 ���裩
����1.���Ƿ�����ڵ�
����2.���Ƿ����ҽڵ�  ���ܷ���ʱ�ʹ�ӡ
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*�ò�ͬ�ķ������ж������ǵݹ����*/
/*���ַ���Ϊ��Ӧ�����Թ��ʣ����ܻ�һ�ַ�ʽ���зǵݹ����ô��
��Ȼ���ַ����ܷϣ�����ͨ���ԱȽϸߣ�ʵ���Ⱥ����������������ʽ����һ����
*/
typedef struct Dong
{
	Node *node;
	int times;//����
	Dong(Node *n, int i = 0) :node(n), times(i){}
}Dong;
void StkNiceInOrder(Node *node)
{
	Dong *d = new Dong(node, 0);
	stack<Dong*> s;
	s.push(d);
	while (!s.empty())
	{
		d = s.top();
		s.pop();
		if (++(d->times) == 1)
		{
			s.push(d);
			if (d->node->left != NULL)					//times == 1��ʱ��Ӧ��������
				s.push(new Dong(d->node->left));
		}
		else if (d->times == 2)
		{
			cout << d->node->val << "   ";
			s.push(d);
			if (d->node->right != NULL)					//times == 2��ʱ��Ӧ�����Һ���
				s.push(new Dong(d->node->right));
		}
	}
	cout << endl;
}
void StkNicePostOrder(Node *node)
{
	Dong *d = new Dong(node, 0);
	stack<Dong*> s;
	s.push(d);
	while (!s.empty())
	{
		d = s.top();
		s.pop();
		if (++(d->times) == 1)
		{
			s.push(d);
			if (d->node->left != NULL)
				s.push(new Dong(d->node->left));
		}
		else if (d->times == 2)
		{
			s.push(d);
			if (d->node->right != NULL)
				s.push(new Dong(d->node->right));
		}
		else
			cout << d->node->val << "   ";
	}
	cout << endl;
}
void StkNicePreOrder(Node *node)
{
	Dong *d = new Dong(node, 0);
	stack<Dong*> s;
	s.push(d);
	while (!s.empty())
	{
		d = s.top();
		s.pop();
		if (++(d->times) == 1)
		{
			cout << d->node->val << "   ";
			s.push(d);
			if (d->node->left != NULL)
				s.push(new Dong(d->node->left));
		}
		else if (d->times == 2)
		{
			s.push(d);
			if (d->node->right != NULL)
				s.push(new Dong(d->node->right));
		}
	}
	cout << endl;
}

int main1()
{
	char a[] = { '1', '2', '3', ' ', ' ', '4', ' ', ' ', '5', '6' };//ע������Ҫ�����ո���Ϊ������������ҪNULL
	int i = 0;
	Tree root = NULL;
	//�ȴ���һ����
	createTree(root, a, i);
	cout << "�ݹ��������" << endl;
	//�ݹ��������
	inOrderY(root);//3   2   4   1   6   5
	cout << endl << endl << "�ǵݹ��������" << endl;
	//�ǵݹ��������
	inOrder(root);//3   2   4   1   6   5


	cout << endl << endl << "�ݹ��������" << endl;
	//�ݹ��������
	preOrderY(root);
	//�ǵݹ��������
	cout << endl << endl << "�ǵݹ��������" << endl;
	preOrder(root);


	cout << endl << endl << "�ݹ�������" << endl;
	//�ݹ�������
	postOrderY(root);
	//�ǵݹ�������
	cout << endl << endl << "�ǵݹ�������" << endl;
	postOrder(root);

	cout << endl << endl << "�ǵݹ��������ڶ��ַ���" << endl;
	postOrder2(root);

	cout << endl << "---------------��һ��˼·д�ǵݹ�-------------------------" << endl;
	cout << "����" << endl;
	StkNiceInOrder(root);
	cout << "����" << endl;
	StkNicePreOrder(root);
	cout << "����" << endl;
	StkNicePostOrder(root);
	cin.get();
	return 0;
}
/*
���� �����ļ������
����1��ʲôʱ����ʸ���ʲôʱ�������������ʲô����������
��������Ϊ�ջ����������Ѿ���������Ժ��ٷ��ʸ�
������ϸ��Ժ��ٷ�����������
����2��Ϊʲô��ջ���������������С�
���ߵ��ĺ���ʡ����ߵ����ȷ��ʣ���Ȼ��ջ�ṹ
����3���������·�����
����1����������·�����
�����������������ý����ջ��
������û�������������ʸý�㣻
����3��·���������
�����������������ظ�����1��
������û������������������ϣ������ˣ���ջ��Ԫ�س�ջ������ջ��Ԫ�أ����������������ظ�����1
���ջΪ�գ���ʾ����������
ע�⣺��ջ�Ľ���ʾ������û�б����ʹ���ͬʱ������Ҳû�б����ʹ���
����4����һ��һֱ��������ջ�Ĳ���

*/