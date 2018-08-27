#pragma once
#include<list>
#include<iostream>
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


template<typename T>
inline void LruList<T>::init(int c)
{
	size = 0;
	this->capacity = c;
	data = new T[c];
	record.clear();
}

template<typename T>
inline int LruList<T>::allocate(const T & item, bool & valid, T & result)
{
	int next = 0; // ��һ�������λ��
	if (size == capacity) { // ����
		next = record.back();

		valid = true;
		result = data[next];

		// ����LRU��¼
		record.pop_back();
		record.push_front(next);
	}
	else { // ���п�λ
		valid = false;

		next = size;
		record.push_front(next); // ��¼��LRU��
		size++;
	}
	data[next] = item; // ��������
	return next;
}

template<typename T>
inline void LruList<T>::visitByIndex(const int index)
{
	for (auto it = record.begin(); it != record.end(); )
	{
		if (*it == index)
		{
			record.erase(it++); // ɾ���ڵ㣬������һ���ڵ�
			break;
		}
		else ++it;
	}
	record.push_front(index); // ����ͷ��
}

template<typename T>
inline int LruList<T>::hasElement(const T & item)
{
	if (record.empty()) return -1;
	for (int i = 0; i < size; i++) if (data[i] == item) return i;
	return -1;
}

template<typename T>
inline T & LruList<T>::get(int index)
{
	return data[index];
}

template<typename T>
inline void LruList<T>::reset(int c)
{
	delete[] data;
	data = NULL;
	init(c);
}

template<typename T>
inline int LruList<T>::getSize() const
{
	return size;
}

template<typename T>
inline int LruList<T>::getCapacity() const
{
	return capacity;
}


template<typename T>
inline void LruList<T>::print()
{
	if (record.empty()) return;
	cout << endl;
	cout << "---------- LruList.print() ----------" << endl;
	for (auto it = record.begin(); it != record.end(); it++) cout << data[*it] << ' ';
	cout << endl;
}
