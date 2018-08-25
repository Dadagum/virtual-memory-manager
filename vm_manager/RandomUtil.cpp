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
	int exp = log(size) / log(2); // 数值的指数位
	int halfBits = 19 + exp;
	int half = pow(2, halfBits); // 一半的数值大小，化为 2^n 的形式
	int shift = bits - halfBits; // 计算需要右移的位数
	int next = (rand() << 15) + rand();
	next = next >> shift;
	return next - half * ( rand() % 2 ); // 最高最低位各一半
}

Address * RandomUtil::nextAddressList(int round, int & total, int size)
{
	total = round * (1 + SysConfig::RAN_LIST);
	Address * tmp = new Address[total];
	for (int cur = 0, r = 0; r < round; r++, cur += SysConfig::RAN_LIST + 1) {
		int address = nextAddressValue(size);
		for (int i = 0; i <= SysConfig::RAN_LIST; i++) tmp[cur + i].value = address + i;
	}
	return tmp;
}
