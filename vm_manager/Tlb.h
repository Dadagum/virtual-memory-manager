#pragma once
#include"TlbEntry.h"
#include"LruList.h"

/*
	TLB数据结构
*/
class Tlb {
private:
	LruList<TlbEntry> * entries;
public:
	static const int TLB_MISS;
	static const int TLBE_EMPTY;
	Tlb() {
		entries = new LruList<TlbEntry>(SysConfig::TLB);
	}
	~Tlb() {
		delete entries;
	}
	void clear(); // 清理TLB项内容
	int getfNumber(int pNumber); // 根据虚页号找到页框号；返回TLB_MISS，表示TLB没有记录；具有记录时返回页框号，同时更新TLB的访问记录
	void allocate(int pNumber, int fNumber);
};