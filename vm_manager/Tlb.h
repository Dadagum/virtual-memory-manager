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
	// 清理TLB项内容
	void clear() {
		for (int i = 0; i < SysConfig::TLB; i++) {
			entries[i].fNumber = SysConfig::TLB_EMPTY;
			entries[i].pNumber = SysConfig::TLB_EMPTY;
		}
	}
};