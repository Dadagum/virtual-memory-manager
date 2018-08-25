#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include"CachePool.h"
#include"LruList.h"
#include<cmath>

/*
	内存数据结构
*/
class Memory {
private:
	LruList<PageFrame> * memory;
public:
	CachePool<PageFrame> * cache; // 缓存，缓存已经被替换的页框号，pid作为key

	Memory() {
		int capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		memory = new LruList<PageFrame>(capacity);
		cache = new CachePool<PageFrame>(SysConfig::PROCESS);
	}
	~Memory() {
		delete memory;
		delete cache;
	}
	int allocate(const PageFrame & frame); // 分配一个页框，此处的pNumber只是PTn的值，返回新分配的页框号
	void visit(int fNumber); // 更新LRU序列
};