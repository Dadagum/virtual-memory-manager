#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include"LruList.h"
#include<cmath>

/*
	�ڴ����ݽṹ
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
	int allocate(int pid, int pNumber); // ����һ��ҳ�򣬴˴���pNumberֻ��PTn��ֵ
	int visit(int fNumber); // ����LRU����
};