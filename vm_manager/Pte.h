#pragma once

/*
	页表项
*/
class Pte {
public:
	bool present; // (在|不在)位
	int number; // 页框号|下一级页表的所在位置
	Pte() {
		present = false;
		number = -1;
	}
	void setValue(bool p, bool n) {
		present = p;
		number = n;
	}
};