#pragma once
#include"SysConfig.h"

/*
	TLB����
*/
class TlbEntry {
public:
	int pNumber; // ��ҳ��
	int fNumber; // ҳ���
	TlbEntry() {
		pNumber = SysConfig::TLB_EMPTY;
		fNumber = SysConfig::TLB_EMPTY;
	}
	void setValue(int p, int f) {
		pNumber = p;
		fNumber = f;
	}
};