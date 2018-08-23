#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include"LruList.h"
#include<cmath>

/*
	内存数据结构
*/
class Memory {
private:
	LruList<PageFrame> * memory;
	int capacity;
	int size;
public:
	Memory() {
		size = 0;
		capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		memory = new LruList<PageFrame>(capacity);
	}
	~Memory() {
		delete memory;
	}
	int allocate(int pid, int pNumber); // 分配一个页框，此处的pNumber只是PTn的值
	int visit(int fNumber); // 更新LRU序列
};