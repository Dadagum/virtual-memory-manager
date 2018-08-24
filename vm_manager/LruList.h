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
	void init(int c); // ��ʼ��
public:
	LruList(int c) {
		init(c);
	}
	~LruList() {
		delete[] data;
	}

	// ����ĳһ�������ݣ����ظ����ݲ�������ڵ�С��λ��
	// �����Ԫ�ر����ǣ���ôvalidλΪtrue��������result��ȡ�þ�Ԫ�ص�ֵ
	int allocate(const T & item,  bool & valid, T & result); 
	void visitByIndex(const int index); // ����һ�����ݣ��������������ڵ��±�
	int hasElement(const T & item); // �鿴ĳһ��Ԫ���Ƿ����б���
	T & get(int index);
	void reset(int capacity); // ��ԭ
	int getSize() const;
	int getCapacity() const;
	void print();
};
