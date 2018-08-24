#pragma once
#include"SysConfig.h"

/*
	地址数据结构
*/
class Address {
private:
	int value;
public:
	Address(int val = 0) {
		value = val;
	}
	int getNumber(const int start, const int end) const; // 从开始位置划分到结束位置，得到该部分组成的数，区间[start, end)
	int getNumber(const int start) const ;
	void setValue(int val);
	int getValue() const;
};  