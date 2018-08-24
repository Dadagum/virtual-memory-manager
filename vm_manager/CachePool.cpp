#include"CachePool.h"
#include<iostream>
using namespace std;

template<typename T>
CachePool<T>::CachePool(int capacity)
{
	this->capacity = capacity;
	cache = new list<T>[capacity];
	size = new int[capacity];
	for (int i = 0; i < capacity; i++) size[i] = 0;
}

template<typename T>
CachePool<T>::~CachePool()
{
	delete[] cache;
	delete[] size;
}

template<typename T>
int CachePool<T>::getSize(int index) const
{
	return size[index];
}

template<typename T>
void CachePool<T>::put(int index, const T & item)
{
	cache[index].push_back(item);
	size[index]++;
}

template<typename T>
T CachePool<T>::pop(int index)
{
	T tmp = cache[index].back();
	cache[index].pop_back();
	size[index]--;
	return tmp;
}

template<typename T>
bool CachePool<T>::isEmpty(int index) const
{
	return size[index] == 0;
}
