#include <iostream>
#include <cstring>
using namespace std;

//�����������
struct LinkNode
{
	char val;
	LinkNode *next;
};
LinkNode *create(char *str)
{
	if (!str)
		return NULL;
	LinkNode *head = new LinkNode;
	head->val = *str++;
	LinkNode *temp = head;
	while (*str)
	{
		LinkNode *node = new LinkNode;
		node->val = *str++;
		temp->next = node;
		temp = temp->next;
	}
	temp->next = NULL;
	return head;
}
//�ǵݹ� 
LinkNode *reverseList(LinkNode *head)
{
	if (!head)
		return NULL;
	LinkNode *pre = NULL, *node = head, *next;
	while (node)
	{
		next = node->next;
		node->next = pre;
		pre = node;
		node = next;
	}
	return pre;
}
//�ݹ�
LinkNode *reverseList2(LinkNode *pre,LinkNode *cur)
{
	LinkNode *head = NULL;//ע��Ҫ��ͷ�������� 
	if(cur){
		head = reverseList2(cur,cur->next);
		cur->next = pre;
	}
	else
		head = pre;
	return head;
}
LinkNode *reverseList2(LinkNode *head)
{
	if(!head) return NULL;
	return reverseList2(NULL,head);
} 

void print(LinkNode *head)
{
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int main()
{
	LinkNode *head = create("abcd");
	print(head);
	LinkNode *reHead = reverseList(head);
	print(reHead);
	LinkNode *reHead2 = reverseList2(reHead);
	print(reHead2);
}

