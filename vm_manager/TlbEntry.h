#pragma once
#include"Constant.h"

/*
	TLB����
*/
class TlbEntry {
private:
	unsigned pNumber; // ��ҳ��
	unsigned fNumber; // ҳ���
	bool used; // ��λ���Ƿ�ʹ��
public:
	TlbEntry() {
		setValue(0, 0, false);
	}
	TlbEntry(unsigned p, unsigned f) {
		setValue(p, f, false);
	}

	void clear() {
		setValue(0, 0, false);
	}
	void setValue(unsigned p, unsigned f, bool u = true) {
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