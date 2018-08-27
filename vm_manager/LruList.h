#pragma once
#include<list>
#include<iostream>
using namespace std;
/*
	方便TLB和物理内存使用的数据结构，使用数组存放数据，使用链表模拟LRU方式
*/
template<typename T>
class LruList {
private:
	int capacity; // 最大容量
	int size; // 现在大小
	list<int> record; // LRU
	T * data;
	void init(int c); // 初始化
public:
	LruList(int c) {
		init(c);
	}
	~LruList() {
		delete[] data;
	}

	// 插入某一个新数据，返回该数据插入后所在的小标位置
	// 如果旧元素被覆盖，那么valid位为true，可以在result中取得旧元素的值
	int allocate(const T & item,  bool & valid, T & result); 
	void visitByIndex(const int index); // 访问一个数据，传来此数据所在的下标
	int hasElement(const T & item); // 查看某一个元素是否在列表中
	T & get(int index);
	void reset(int capacity); // 还原
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
	int next = 0; // 下一个插入的位置
	if (size == capacity) { // 满了
		next = record.back();

		valid = true;
		result = data[next];

		// 更新LRU记录
		record.pop_back();
		record.push_front(next);
	}
	else { // 仍有空位
		valid = false;

		next = size;
		record.push_front(next); // 记录在LRU中
		size++;
	}
	data[next] = item; // 插入数据
	return next;
}

template<typename T>
inline void LruList<T>::visitByIndex(const int index)
{
	for (auto it = record.begin(); it != record.end(); )
	{
		if (*it == index)
		{
			record.erase(it++); // 删除节点，并到下一个节点
			break;
		}
		else ++it;
	}
	record.push_front(index); // 插入头部
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
