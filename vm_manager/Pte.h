#pragma once
#include<iostream>

/*
	ҳ����
*/
class Pte {
public:
	bool present; // (��|����)λ
	int number; // �������ײ㣬��ô����ȡ��ҳ���;��������һ��ҳ��ĵ�ַ������Ϊ�˼���һ��������±��
	Pte() {
		present = false;
		number = -1;
	}
	void setValue(bool p, bool n) {
		present = p;
		number = n;
	}
};