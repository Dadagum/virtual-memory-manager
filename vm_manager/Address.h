#pragma once

/*
	地址数据结构
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
	int getNumber(const int start, const int end) const; // 从开始位置划分到结束位置，得到该部分组成的数
	int getNumber(const int start) const ;
};