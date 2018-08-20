#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include<cmath>

/*
	内存数据结构
*/
class Memory {
private:
	PageFrame * pf;
	int curr; // 指向空余的位置
	int capacity; // 容纳的最多页框数量
public:
	Memory() {
		capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		curr = 0;
		pf = new PageFrame[capacity];
	}
	~Memory() {
		delete [] pf;
	}
	void allocate(int pid, int pNumber);
	void update(int fNumber);
};