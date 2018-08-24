#pragma once
#include"Constant.h"

/*
	TLB����
*/
class TlbEntry {
private:
	int pNumber; // ��ҳ��
	int fNumber; // ҳ���
	bool used; // ��λ���Ƿ�ʹ��
public:
	TlbEntry() {
		setValue(0, 0, false);
	}
	TlbEntry(int p, int f) {
		setValue(p, f, false);
	}

	void clear() {
		setValue(0, 0, false);
	}
	void setValue(int p, int f, bool u = true) {
		pNumber = p;
		fNumber = f;
		used = u;
	}
	bool operator==(const TlbEntry & entry) {
		return pNumber == entry.pNumber && fNumber == entry.fNumber;
	}
	int getpNumber() const {
		return pNumber;
	}
	int getfNumber() const {
		return fNumber;
	}
};