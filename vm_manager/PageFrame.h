#pragma once

/*
	页框数据结构
*/
class PageFrame {
private:
	int pid; // 属于哪一个进程的数据
	int pNumber; // 属于该进程的虚拟页号
public:
	PageFrame() {
		pid = 0;
		pNumber = 0;
	}
};