#pragma once
#include<list>
using namespace std;
/*
	方便TLB和物理内存使用的数据结构，使用数组存放数据，使用链表模拟LRU方式
*/
template<typename T>
class LruList {
private:
	int capacity; // 最大容量
	int size; // 现在大小
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
	void allocate(T item); // 插入某一个数据
	void visit(T item); // 访问某一个数据
	T at(int index); // 下标index的值
};
