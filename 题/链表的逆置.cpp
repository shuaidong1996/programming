#include <iostream>
using namespace std;

typedef struct dong{
	char val;
	dong *next;
}Node;

/*��ͷ���*/
Node* create_NO_head()
{
	char ch;
	ch = getchar();
	//��������new�жϱȽϺ� 
	//	try
	//	{
	//		Node *root = new Node;
	//	}
	//	catch(const bad_alloc &e)
	//	{
	//		return -1;
	//	}
	//��
	Node *root = new (nothrow)Node;
	if (NULL == root)
		return NULL;
	if (ch == '#')
		return NULL;
	root->val = ch;
	Node *temp = root;
	Node *node;
	while ((ch = getchar()) != '#')
	{
		node = new Node;
		if (NULL == root)
			return NULL;
		node->val = ch;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}
	return root;
}
void print(Node *n)
{
	if (n != NULL)
	{
		cout << n->val << endl;
		print(n->next);
	}
}

/*�ݹ鷽ʽ*/ 
Node *reverse_sys(Node *pre, Node *cur)
{
	Node *t = NULL;
	if (cur != NULL)
	{
		t = reverse_sys(cur, cur->next);
		cur->next = pre;
		pre->next = NULL;
	}
	else
		t = pre;
	return t;
}
void reverse(Node *&node)
{
	node = reverse_sys(node, node->next);
}
/*�ڶ��ַ���  �򵥵�*/
void reverse_sys2(Node *cur, Node *&head)
{
	if(cur->next == NULL)
	{
		head = cur;
		return;
	}
	Node *next = cur->next;
	reverse_sys2(next,head);
	next->next = cur;
	cur->next = NULL;
}
void reverse2(Node *&node)
{
	reverse_sys2(node, node);
}

/*�ǵݹ�ʵ��*/
void reverse3(Node *&node)
{
	Node *temp;
	Node *p = node;
	node = node->next;
	p->next = NULL;
	while(node->next)
	{
		temp = node->next;
		node->next = p;
		p = node;
		node = temp;
	}
	node->next = p;
}

/*��ͷ����*/
Node *create_head()
{
	char ch;
	Node *root = new (nothrow)Node;
	if (NULL == root)
		return NULL;
	Node *temp = root;
	Node *node;
	while ((ch = getchar()) != '#')
	{
		node = new (nothrow) Node;
		if (NULL == root)
			return NULL;
		node->val = ch;
		node->next = NULL;
		temp->next = node;
		temp = node;
	}
	return root;	
}
void print2(Node* node)
{
	node = node->next;
	if(node)
	{
		cout<<node->val<<endl;
		print(node->next);
	}
}

/*�ݹ鷽ʽ*/ 
void reverse_sys4(Node *cur, Node *&head)
{
	if(cur->next == NULL)
	{
		head->next = cur;					//�Ķ��ĵط�************* 
		return;
	}
	Node *next = cur->next;
	reverse_sys4(next,head);
	next->next = cur;
	cur->next = NULL;
}
void reverse4(Node *&node)
{
	reverse_sys4(node->next, node);			//�Ķ��ĵط�************* 
}

/*�ǵݹ�ʵ��*/
void reverse5(Node *&head)				//�Ķ��ĵط�*************  
{
	Node *node = head;					//�Ķ��ĵط�************* 
	node = node->next;					//�Ķ��ĵط�************* 
	Node *temp;
	Node *p = node;
	node = node->next;
	p->next = NULL;
	while(node->next)
	{
		temp = node->next;
		node->next = p;
		p = node;
		node = temp;
	}
	node->next = p;
	head->next = node;					//�Ķ��ĵط�************* 
}
int main()
{
	Node *node = create_head();
	print2(node);
	reverse5(node);
	print2(node);
}
