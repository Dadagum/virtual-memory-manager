#pragma once
#include"Constant.h"

/*
	TLB表项
*/
class TlbEntry {
private:
	unsigned pNumber; // 虚页号
	unsigned fNumber; // 页框号
	bool used; // 该位置是否使用
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