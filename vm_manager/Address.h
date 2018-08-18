#pragma once

/*
	地址
*/
class Address {
private:
	char * bits; // 地址位
public:
	Address(int length) {
		bits = new char[length];
	}
	~Address() {
		delete[] bits;
	}
	int getNumber(int start, int end); // 从开始位置划分到结束位置，得到该部分组成的数
};