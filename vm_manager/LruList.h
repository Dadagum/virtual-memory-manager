#pragma once
#include<list>
using namespace std;
/*
	����TLB�������ڴ�ʹ�õ����ݽṹ��ʹ�����������ݣ�ʹ������ģ��LRU��ʽ
*/
template<typename T>
class LruList {
private:
	int capacity; // �������
	int size; // ���ڴ�С
	list<int> record;
	T * data;
public:
	LruList(int capacity) {
		this->capacity = capacity;
		data = new T[capacity];
	}
	~LruList() {
		delete[] data;
	}
	void allocate(T item); // ����ĳһ������
	void visit(T item); // ����ĳһ������
	T at(int index); // �±�index��ֵ
};

template<typename T>
inline void LruList<T>::allocate(T item)
{
}

template<typename T>
inline void LruList<T>::visit(T item)
{
}

template<typename T>
inline T LruList<T>::at(int index)
{
	return T();
}
