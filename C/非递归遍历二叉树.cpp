#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

typedef struct NODE{
	char val;
	struct NODE *left,*right;
	NODE(int val) :val(val), left(NULL), right(NULL){}
}Node, *Tree;

void createTree(Tree &t,char a[],int &i)//ע���������Ǳ�����&���ã���Ϊ����Ҫ�ı䴫������root�ĵ�ַ��ҪΪ�������ڴ棩
{
	if (i > 9 || a[i] == ' ')
	{
		t = NULL;
		return;
	}
	cout << a[i] <<"+++"<< endl;

	t = new Node(a[i]);
	createTree(t->left,a,++i);
	createTree(t->right,a,++i);
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
//�ǵݹ��������

void preOrder(Tree t)
{
	if(!t)
		return;
	stack<Tree> s;
	Tree p = t;
	while(!s.empty() || p)
	{
		if(p)
		{
			cout<<p->val<<"  ";
			s.push(p);
			p = p->left;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
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
//�ǵݹ�������
void postOrder(Tree t)
{
	if (!t)
		return;
	Tree p = t;
	Tree pLastVisit = NULL;//pLastVisit:�ϴη��ʽڵ�
	stack<Tree> s;
	while(p)
	{
		s.push(p);
		p = p->left;
	}
	while(!s.empty())
	{
		p = s.top();
		s.pop();
		if(!p->right || pLastVisit == p->right)
		{
			cout<<p->val<<"   ";
			pLastVisit = p;
		}
		else
		{
			s.push(p);
			p = p->right;
			while(p)
			{
				s.push(p);
				p = p->left;
			}
		}
	}
}
int main()
{
	char a[] = { '1', '2', '3', ' ', ' ', '4', ' ', ' ', '5', '6' };//ע������Ҫ�����ո���Ϊ������������ҪNULL
	int i = 0;
	Tree root = NULL;
	//�ȴ���һ����
	createTree(root, a, i);
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

	cin.get();
	return 0;
}
