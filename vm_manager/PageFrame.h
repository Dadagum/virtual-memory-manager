#pragma once

/*
	页框数据结构
*/
class PageFrame {
private:
	int pid; // 属于哪一个进程的数据
public:
	PageFrame() {
		pid = 0;
	}
	PageFrame(int id) {
		pid = id;
	}
	bool operator==(const PageFrame & frame) {
		return pid == frame.pid;
	}
	int getPid() const {
		return pid;
	}
};