#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include"CachePool.h"
#include"LruList.h"
#include<cmath>

/*
	�ڴ����ݽṹ
*/
class Memory {
private:
	LruList<PageFrame> * memory;
public:
	CachePool<PageFrame> * cache; // ���棬�����Ѿ����滻��ҳ��ţ�pid��Ϊkey

	Memory() {
		int capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		memory = new LruList<PageFrame>(capacity);
		cache = new CachePool<PageFrame>(SysConfig::PROCESS);
	}
	~Memory() {
		delete memory;
		delete cache;
	}
	int allocate(const PageFrame & frame); // ����һ��ҳ�򣬴˴���pNumberֻ��PTn��ֵ�������·����ҳ���
	void visit(int fNumber); // ����LRU����
};