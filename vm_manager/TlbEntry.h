#pragma once
#include"SysConfig.h"

/*
	TLB±íÏî
*/
class TlbEntry {
public:
	int pNumber; // ÐéÒ³ºÅ
	int fNumber; // Ò³¿òºÅ
	TlbEntry() {
		pNumber = SysConfig::TLB_EMPTY;
		fNumber = SysConfig::TLB_EMPTY;
	}
	void setValue(int p, int f) {
		pNumber = p;
		fNumber = f;
	}
};