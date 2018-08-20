#pragma once
#include"SysConfig.h"

/*
	TLB±íÏî
*/
class TlbEntry {
private:
	int pNumber; // ÐéÒ³ºÅ
	int fNumber; // Ò³¿òºÅ
public:
	TlbEntry() {
		clear();
	}
	void setValue(int p, int f) {
		pNumber = p;
		fNumber = f;
	}
	void clear() {
		pNumber = SysConfig::TLBE_EMPTY;
		fNumber = SysConfig::TLBE_EMPTY;
	}
};