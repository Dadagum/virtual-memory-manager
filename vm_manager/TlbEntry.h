#pragma once
#include"SysConfig.h"

/*
	TLB����
*/
class TlbEntry {
private:
	int pNumber; // ��ҳ��
	int fNumber; // ҳ���
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