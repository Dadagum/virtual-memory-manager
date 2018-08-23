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
	list<int> record; // LRU
	T * data;
public:
	LruList(int capacity) {
		size = 0;
		this->capacity = capacity;
		data = new T[capacity];
		record.clear();
	}
	~LruList() {
		delete[] data;
	}

	// ����ĳһ�������ݣ����ظ����ݲ�������ڵ�С��λ��
	// �����Ԫ�ر����ǣ���ôvalidλΪtrue��������result��ȡ�þ�Ԫ�ص�ֵ
	int allocate(const T & item,  bool & valid, T & result); 
	void visit(const T & item); // ����ĳһ������
	void visitByIndex(const int index); // ����һ�����ݣ��������������ڵ��±�
	int hasElement(const T & item); // �鿴ĳһ��Ԫ���Ƿ����б���
	T & operator[](int index);
	void print();
};
