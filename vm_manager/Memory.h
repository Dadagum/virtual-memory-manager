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
public:
	Memory() {
		int capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		memory = new LruList<PageFrame>(capacity);
	}
	~Memory() {
		delete memory;
	}
	int allocate(int pid, int pNumber);
	int visit(int fNumber);
};