#pragma once
#include"SysConfig.h"

/*
	��ַ���ݽṹ
*/
class Address {
public:
	int value;
	Address(int val = 0) {
		value = val;
	}
	int getNumber(const int start, const int end) const; // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���������[start, end)
	int getNumber(const int start) const ;
};  