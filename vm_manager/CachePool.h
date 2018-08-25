#pragma once
#include<list>
#include<iostream>
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


template<typename T>
inline CachePool<T>::CachePool(int capacity)
{
	this->capacity = capacity;
	cache = new list<T>[capacity];
	size = new int[capacity];
	for (int i = 0; i < capacity; i++) size[i] = 0;
}

template<typename T>
inline CachePool<T>::~CachePool()
{
	delete[] cache;
	delete[] size;
}

template<typename T>
inline int CachePool<T>::getSize(int index) const
{
	return size[index];
}

template<typename T>
inline void CachePool<T>::put(int index, const T & item)
{
	cache[index].push_back(item);
	size[index]++;
}

template<typename T>
inline T CachePool<T>::pop(int index)
{
	T tmp = cache[index].back();
	cache[index].pop_back();
	size[index]--;
	return tmp;
}

template<typename T>
inline bool CachePool<T>::isEmpty(int index) const
{
	return size[index] == 0;
}


