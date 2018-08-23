#include"LruList.h"
#include<iostream>
using namespace std;

template<typename T>
int LruList<T>::allocate(const T & item,  bool & valid, T & result)
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
void LruList<T>::visit(const T & item)
{
}

template<typename T>
void LruList<T>::visitByIndex(const int index)
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
int LruList<T>::hasElement(const T & item)
{
	if (record.empty()) return -1;
	for (int i = 0; i < size; i++) if (data[i] == item) return i;
	return -1;
}

template<typename T>
T & LruList<T>::operator[](int index)
{
	return data[index];
}

template<typename T>
void LruList<T>::print()
{
	if (record.empty()) return;
	cout << endl;
	cout << "---------- LruList.print() ----------" << endl;
	for (auto it = record.begin(); it != record.end(); it++) cout << data[*it] << ' ';
	cout << endl;
}

