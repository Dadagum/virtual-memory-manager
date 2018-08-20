#pragma once
#define LIST_END -1
/*
	����TLB�������ڴ�ʹ�õĻ��������listʵ�֣���λ����ô��װ����С��˳��ֵ�����û��λ�������LRU�ķ�������
*/
template<typename T>
class LruList {
private:
	int capacity; // �������
	int size; // ���ڴ�С
	int head; // ͷ����Ҳ������֮���һ�����û���ȥ��λ��
	int tail; // β��
	int pos; // ���û��������ô��һ�������λ��
	T * data; 
public:
	LruList(int capacity) {
		this->capacity = capacity;
		size = 0;
		head = 0;
		tail = -1;
	}
	~LruList() {
		delete[] data;
	}

	void allocate(T item); // ����ĳһ������
	void visit(T item); // ����ĳһ������
	T at(int index); // �±�index��ֵ
};
