#pragma once
#include"Address.h"

/*
	�����������
*/
class RandomUtil {
private:
	int bits; // ��������������λ�����˴�Ϊ30��1�� 2^30-1 = (RAND_MAX << 15) + RAND_MAX 
	int nextAddressValue(int size); // ����һ��(���ݸ���ĿҪ��)����ĵ�ַ��size�ĵ�λ��MB
public:
	RandomUtil();
    Address * nextAddressList(int round, int & total, int size); // ���������������ַ����
};