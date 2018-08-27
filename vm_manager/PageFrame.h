#pragma once

/*
	页框数据结构
*/
class PageFrame {
private:
	int pid; // 属于哪一个进程的数据
	unsigned va; // 属于进程的虚拟地址，值只是ptn，方便页框被替换时更新原进程的页表
public:
	PageFrame() {
		pid = 0;
		va = -1;
	}
	PageFrame(int id, unsigned v) {
		pid = id;
		va = v;
	}
	bool operator==(const PageFrame & frame) {
		return pid == frame.pid;
	}
	int getPid() const {
		return pid;
	}
	int getVa() const {
		return va;
	}
};