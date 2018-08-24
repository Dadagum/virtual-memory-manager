#pragma once

/*
	ҳ�����ݽṹ
*/
class PageFrame {
private:
	int pid; // ������һ�����̵�����
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