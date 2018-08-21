#pragma once
#include"Constant.h"

/*
	TLB±íÏî
*/
class TlbEntry {
private:
	int pNumber; // ĞéÒ³ºÅ
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
		pNumber = Constant::TLBE_EMPTY;
		fNumber = Constant::TLBE_EMPTY;
	}
};