#include "RandomUtil.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

RandomUtil::RandomUtil()
{
	srand((unsigned)time(NULL));
	bits = 30;
}

int RandomUtil::nextAddressValue(int size)
{
	// TODO
	int exp = log(size) / log(2); // 数值的指数位
	int half = pow(2, 20 + exp - 1); // 一半的数值大小
	int shift = bits - 21; // 计算需要右移的位数
	int next = (rand() << 15) + rand();
	return 0;
}

Address * RandomUtil::nextAddressList(int round, int & total, int size)
{

	return nullptr;
}
