#ifndef Node_H
#define Node_H
#include <string>

/* ʵ��ڵ� */
class Node
{
public:
	Node(std::string nodeName, int vNodeNum)
		:nodeName(nodeName), vNodeNum(vNodeNum){}
	~Node(){}
	int GetVNodeNum(){ return vNodeNum; }
	std::string GetNodeName(){ return nodeName; }
private:
	std::string nodeName;//�ڵ�����Ҳ�Ƿ�������
	int vNodeNum;//����ڵ����
};

#endif