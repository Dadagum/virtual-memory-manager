#pragma once
#include"SysConfig.h"

/*
	��ַ���ݽṹ
*/
class Address {
private:
	int value;
public:
	Address(int val = 0) {
		value = val;
	}
	int getNumber(const int start, const int end) const; // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���������[start, end)
	int getNumber(const int start) const ;
	void setValue(int val);
	int getValue() const;
};  