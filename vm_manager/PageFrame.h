#pragma once

/*
	ҳ�����ݽṹ
*/
class PageFrame {
private:
	int pid; // ������һ�����̵�����
	int pNumber; // ���ڸý��̵�����ҳ��
	int fNumber;
public:
	PageFrame() {
		pid = 0;
		pNumber = 0;
		fNumber = 0;
	}
	bool operator==(const PageFrame & frame) {
		return pid == frame.pid && pNumber == frame.pNumber && fNumber == frame.fNumber;
	}
};