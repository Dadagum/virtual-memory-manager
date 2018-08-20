#pragma once
#include"TlbEntry.h"

/*
	TLB数据结构
*/
class Tlb {
private:
	TlbEntry * entries;
public:
	Tlb() {
		entries = new TlbEntry[SysConfig::TLB];
	}
	~Tlb() {
		delete[] entries;
	}
	// 清理TLB项内容
	void clear() {
		for (int i = 0; i < SysConfig::TLB; i++) entries[i].clear();
	}
	// 根据虚页号找到页框号，返回TLB_MISS表TLB没有记录
	int getfNumber(int pNumber);
	// 更新TLB内容
	void update(int pNumber);
};