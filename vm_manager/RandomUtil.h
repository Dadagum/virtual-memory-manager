#pragma once
#include"Address.h"

/*
	�����������
*/
class RandomUtil {
public:
    static Address nextAddress(); // ����һ��(���ݸ���ĿҪ��)����ĵ�ַ
	static Address * nextAddressList(int round, int & total); // ���������������ַ����
};