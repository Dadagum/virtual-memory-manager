#pragma once
#include"TlbEntry.h"

/*
	TLB���ݽṹ
*/
class Tlb {
private:
	TlbEntry * entries;
public:
	Tlb() {
		entries = new TlbEntry[SysConfig::TLB];
	}
	// ����TLB������
	void clear() {
		for (int i = 0; i < SysConfig::TLB; i++) {
			entries[i].fNumber = SysConfig::TLB_EMPTY;
			entries[i].pNumber = SysConfig::TLB_EMPTY;
		}
	}
};