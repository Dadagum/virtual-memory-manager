#pragma once

/*
	ҳ����
*/
class Pte {
public:
	bool present; // (��|����)λ
	int number; // ҳ���|��һ��ҳ�������λ��
	Pte() {
		present = false;
		number = -1;
	}
	void setValue(bool p, bool n) {
		present = p;
		number = n;
	}
};