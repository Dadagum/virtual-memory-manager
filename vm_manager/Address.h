#pragma once

/*
	��ַ���ݽṹ
*/
class Address {
private:
	char * bits; // ��ַλ
public:
	Address(int length) {
		bits = new char[length];
	}
	~Address() {
		delete[] bits;
	}
	int getNumber(const int start, const int end) const; // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���
	int getNumber(const int start) const ;
};