#pragma once
#include"SysConfig.h"

/*
	��ַ���ݽṹ
*/
class Address {
public:
	unsigned value;
	Address(unsigned val = 0) {
		value = val;
	}
	unsigned getNumber(const int start, const int end) const; // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���������[start, end)
	unsigned getNumber(const int start) const ; 
};  