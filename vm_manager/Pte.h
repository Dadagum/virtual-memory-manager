#pragma once
#include<iostream>

/*
	ҳ����
*/
class Pte {
public:
	bool present; // (��|����)λ
	unsigned number; // �������ײ㣬��ô����ȡ��ҳ���;��������һ��ҳ��ĵ�ַ������Ϊ�˼���һ��������±��
	Pte() {
		present = false;
		number = 0;
	}
	void setValue(bool p, unsigned n) {
		present = p;
		number = n;
	}
};