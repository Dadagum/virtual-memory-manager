#pragma once

/*
	页框数据结构
*/
class PageFrame {
private:
	int pid; // 属于哪一个进程的数据
	int pNumber; // 属于该进程的虚拟页号
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