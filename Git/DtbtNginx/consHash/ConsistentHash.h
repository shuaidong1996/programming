#ifndef ConsistentHash_H
#define ConsistentHash_H
#include <map>
#include <list>
#include <string>
#include <vector>
#include <sstream>
#include "Node.h"
#include "HashFunc.h"
#include "MD5HashFunc.h"
class ConsistentHash
{
public:
	ConsistentHash(HashFunc *func = nullptr);
	~ConsistentHash();
	bool addNode(std::string nodeName, int vNum);
	bool delNode(std::string nodeName);
	//����client�Ҷ�Ӧ��server
	std::string getServerName(std::string cliName);
	//��ȡ��ʵ�ڵ����
	int getRealNum();
	//��ȡĳ����ʵ�ڵ������ڵ����
	int getVirNum(std::string serName);
	//��ȡ���нڵ�����
	int getAllNodeNum();
	//��ӡ�ڵ㣨������ʹ�ã�
	std::string showTime();
	//ͳ�ƻ������нڵ�ֲ������������ʹ�ã�
	std::string statDist();
private:
	bool addRealNode(Node *node);
	bool addVirNode(Node *node);
	bool delRealNode(Node *node);
	bool delVirNode(Node *node);
	/* ɾ��realNode�еĽڵ� �� ��������ڵ� */
	Node *findRealNode(std::string &nodeName);
private:
	std::multimap<unsigned int, std::string> allNode;//��multimap������hash��ͻ
	std::list<Node *> realNode;
	HashFunc *hashFunc;
};

#endif