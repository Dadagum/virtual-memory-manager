#pragma once

/*
	��ַ
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
	int getNumber(int start, int end); // �ӿ�ʼλ�û��ֵ�����λ�ã��õ��ò�����ɵ���
};