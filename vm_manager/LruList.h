#pragma once
#define LIST_END -1
/*
	方便TLB和物理内存使用的基于数组的list实现，有位置那么安装数组小标顺序赋值，如果没有位置则采用LRU的方法覆盖
*/
template<typename T>
class LruList {
private:
	int capacity; // 最大容量
	int size; // 现在大小
	int head; // 头部，也是满了之后第一个被置换出去的位置
	int tail; // 尾部
	int pos; // 如果没有满，那么下一个插入的位置
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

	void allocate(T item); // 插入某一个数据
	void visit(T item); // 访问某一个数据
	T at(int index); // 下标index的值
};
