#pragma once
#include"Address.h"

/*
	�����������
*/
class RandomUtil {
private:
	int bits; // ��������������λ�����˴�Ϊ30��1�� 2^30-1 = (RAND_MAX << 15) + RAND_MAX 
public:
	RandomUtil();
    int nextAddressValue(int size); // ����һ��(���ݸ���ĿҪ��)����ĵ�ַ��size�ĵ�λ��MB
    Address * nextAddressList(int round, int & total, int size); // ���������������ַ����
};