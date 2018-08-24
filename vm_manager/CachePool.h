#pragma once
#include<list>
#include"PageFrame.h"
using namespace std;

/*
	缓存
*/
template<typename T>
class CachePool {
private:
	int capacity; // 多个缓冲，使用下标区分
	list<T> * cache;
	int * size;
public:
	CachePool(int capacity);
	~CachePool();
	int getSize(int index) const;
	void put(int index, const T & item);
	T pop(int index);
	bool isEmpty(int index)const;
};


