#pragma once
#include"Constant.h"

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
		pNumber = Constant::TLBE_EMPTY;
		fNumber = Constant::TLBE_EMPTY;
	}
};