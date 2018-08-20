#pragma once
#include"Address.h"

/*
	随机数生成类
*/
class RandomUtil {
public:
    static Address nextAddress(); // 生成一个(根据该题目要求)随机的地址
	static Address * nextAddressList(int round, int & total); // 生成连续的随机地址序列
};