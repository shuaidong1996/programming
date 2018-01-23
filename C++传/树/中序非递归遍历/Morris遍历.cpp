#include "Tree.h"

/*Morris����ʱ�临�Ӷ�ΪO(n)�ռ临�Ӷ�ΪO(1)*/
//����
void MidMorris(Node *root){
	if (!root)
		return;
	Node *cur = root, *pre = NULL;
	while (cur){
		if (!cur->left){
			cout << cur->val << "   ";
			cur = cur->right;
		}
		else{//�����ӿ϶���ǰ���ڵ�ָ���Լ�
			pre = cur->left;
			while (pre->right && pre->right != cur)//!=cur����Ϊ֮ǰ�����Ѿ�ָ����cur
				pre = pre->right;
			if (!pre->right){//˵����ǰ���ڵ�
				pre->right = cur;
				cur = cur->left;
			}
			else{
				cout << cur->val << "   ";//˵������ǰ���ڵ�ͨ��->right�ҵ���cur
				pre->right = NULL;//�ָ�ԭ��
				cur = cur->right;
			}
		}
	}
	cout << endl;
}
//����
void PreMorris(Node *root){
	if (!root)
		return;
	Node *cur = root, *pre = NULL;
	while (cur){
		if (!cur->left){
			cout << cur->val << "   ";
			cur = cur->right;
		}
		else{
			pre = cur->left;
			while (pre->right && pre->right != cur)
				pre = pre->right;
			if (!pre->right){
				cout << cur->val << "   ";//change------
				pre->right = cur;
				cur = cur->left;
			}
			else{
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
	cout << endl;
}
/*
�����������Ը��ӣ���Ҫ����һ����ʱ�ڵ�dump������������root��
���һ���Ҫһ���ӹ��̣����ǵ������ĳ�����ڵ�֮��·���ϵĸ����ڵ㡣
*/
//�൱�����������ӡ---1  ʱ�临�Ӷ�ΪO(N^2)
void printReverse(Node* from, Node *to) {
	if (!from || !to)
		return;
	Node *start = from, *end = to, *pre = from;
	while (start != end){
		while (start != end){
			pre = start;
			start = start->right;
		}
		cout << start->val << "   ";
		end = pre;
		start = from;
	}
	cout << from->val << "   ";
}
//�޸�ָ��ָ��---2  ʱ�临�Ӷ�ΪO(N)
void Reverse(Node *from, Node *to){
	if (!from || !to)
		return;
	Node *pre = from, *cur = pre->right, *next;
	while (cur && pre != to){//����Ϊ�� ��Ϊ����pre�жϵ�
		next = cur->right;
		cur->right = pre;
		pre = cur;
		cur = next;
	}
}
void printReverse2(Node* from, Node *to) {
	if (!from || !to)
		return;
	Reverse(from, to);//������from ָ�� to����  change to ָ��from����
	Node *p = to;
	while (p != from){
		cout << p->val << "   ";
		p = p->right;
	}
	cout << p->val << "   ";
	Reverse(to, from);
}
void PostMorris(Node *root) {
	Node dump(0);//ѭ������������
	dump.left = root;
	Node *cur = &dump, *prev = NULL;
	while (cur) {
		if (cur->left == NULL) {
			cur = cur->right;
		}
		else {
			prev = cur->left;
			while (prev->right != NULL && prev->right != cur)
				prev = prev->right;

			if (prev->right == NULL) {
				prev->right = cur;
				cur = cur->left;
			}
			else {
				printReverse2(cur->left, prev);  // call print
				prev->right = NULL;
				cur = cur->right;
			}
		}
	}
}

int main() {
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
	MidMorris(root);//3   2   4   1   6   5

	cout << endl << endl << "�ݹ��������" << endl;
	//�ݹ��������
	preOrderY(root);
	//�ǵݹ��������
	cout << endl << endl << "�ǵݹ��������" << endl;
	PreMorris(root);

	cout << endl << endl << "�ݹ�������" << endl;
	//�ݹ�������
	postOrderY(root);
	//�ǵݹ�������
	cout << endl << endl << "�ǵݹ�������" << endl;
	PostMorris(root);

	cin.get();
	return 0;
}