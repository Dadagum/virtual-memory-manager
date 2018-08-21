#pragma once
#include"SysConfig.h"

/*
	��ַ���ݽṹ
*/
class Address {
private:
	char * bits; // ��ַλ
	int length;
public:
	Address(int length = SysConfig::VA_BIT) {
		bits = new char[length];
		this->length = length;
	}
	~Address() {
		delete[] bits;
	}
	int getNumber(const int start, const int end) const; // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���������[start, end)
	int getNumber(const int start) const ;
};