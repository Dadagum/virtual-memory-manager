#pragma once
#include<iostream>

/*
	页表项
*/
class Pte {
public:
	bool present; // (在|不在)位
	unsigned number; // 如果是最底层，那么可以取得页框号;否则是下一级页表的地址，但是为了简化用一个数组的下标简化
	Pte() {
		present = false;
		number = 0;
	}
	void setValue(bool p, unsigned n) {
		present = p;
		number = n;
	}
};