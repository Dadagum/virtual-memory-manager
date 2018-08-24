#pragma once
#include<list>
#include"PageFrame.h"
using namespace std;

/*
	����
*/
template<typename T>
class CachePool {
private:
	int capacity; // ������壬ʹ���±�����
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


