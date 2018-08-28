#pragma once
#include"Address.h"

/*
	ҳ�����ݽṹ
*/
class PageFrame {
private:
	int pid; // ������һ�����̵�����
	Address va;
public:
	PageFrame() {
		pid = 0;
	}
	PageFrame(int id, Address v) {
		pid = id;
		va = v;
	}
	bool operator==(const PageFrame & frame) {
		return pid == frame.pid;
	}
	int getPid() const {
		return pid;
	}
	Address getVa() {
		return va;
	}
};