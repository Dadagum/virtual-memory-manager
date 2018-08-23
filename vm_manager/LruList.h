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

	// 插入某一个新数据，返回该数据插入后所在的小标位置
	// 如果旧元素被覆盖，那么valid位为true，可以在result中取得旧元素的值
	int allocate(const T & item,  bool & valid, T & result); 
	void visit(const T & item); // 访问某一个数据
	void visitByIndex(const int index); // 访问一个数据，传来此数据所在的下标
	int hasElement(const T & item); // 查看某一个元素是否在列表中
	T & operator[](int index);
	void print();
};
