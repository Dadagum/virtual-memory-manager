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
	int exp = log(size) / log(2); // ��ֵ��ָ��λ
	int halfBits = 19 + exp;
	int half = pow(2, halfBits); // һ�����ֵ��С����Ϊ 2^n ����ʽ
	int shift = bits - halfBits; // ������Ҫ���Ƶ�λ��
	int next = (rand() << 15) + rand();
	next = next >> shift;
	return next - half * ( rand() % 2 ); // ������λ��һ��
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
