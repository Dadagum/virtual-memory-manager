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
