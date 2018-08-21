#pragma once
#include"SysConfig.h"

/*
	地址数据结构
*/
class Address {
private:
	char * bits; // 地址位
	int length;
public:
	Address(int length = SysConfig::VA_BIT) {
		bits = new char[length];
		this->length = length;
	}
	~Address() {
		delete[] bits;
	}
	int getNumber(const int start, const int end) const; // 从开始位置划分到结束位置，得到该部分组成的数，区间[start, end)
	int getNumber(const int start) const ;
};