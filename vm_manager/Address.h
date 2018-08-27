#pragma once
#include"SysConfig.h"

/*
	地址数据结构
*/
class Address {
public:
	unsigned value;
	Address(unsigned val = 0) {
		value = val;
	}
	unsigned getNumber(const int start, const int end) const; // 从开始位置划分到结束位置，得到该部分组成的数，区间[start, end)
	unsigned getNumber(const int start) const ; 
};  