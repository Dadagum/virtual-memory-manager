#pragma once
#include"Tlb.h"

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
		pNumber = Tlb::TLBE_EMPTY;
		fNumber = Tlb::TLBE_EMPTY;
	}
};