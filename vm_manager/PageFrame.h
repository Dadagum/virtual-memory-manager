#pragma once
#include"Address.h"

/*
	页框数据结构
*/
class PageFrame {
private:
	int pid; // 属于哪一个进程的数据
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