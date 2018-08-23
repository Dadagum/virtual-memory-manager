#pragma once
#include"Address.h"

/*
	随机数生成类
*/
class RandomUtil {
private:
	int bits; // 随机生成数的最大位长，此处为30个1即 2^30-1 = (RAND_MAX << 15) + RAND_MAX 
public:
	RandomUtil();
    int nextAddressValue(int size); // 生成一个(根据该题目要求)随机的地址，size的单位是MB
    Address * nextAddressList(int round, int & total, int size); // 生成连续的随机地址序列
};