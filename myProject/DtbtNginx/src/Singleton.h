#ifndef SIGNLETON_H
#define SIGNLETON_H
/* ͨ�õĵ���ģ�� */
template<typename T>
class Singleton
{
private:
	Singleton(){}
	virtual ~Singleton(){}
	static T *instance;
public:
	static T *getInstence(){ return instance; }
};
template<typename T>
T *Singleton<T>::instance = new T;
#endif