#pragma once
#include<iostream>
#include"TwoLevelVmSys.h"

/*
	进程
*/
class Process {
private:
	int size; // 进程大小
	int pid; // 进程标识符
public:
	char * ptFile; // 将页表内容保存到外部文件的文件名称
	Process(int size, int id) {
		this->size;
		this->pid = id;
		// 初始化ptFile
		// TODO
	}
	void setSize(int size) {
		this->size = size;
	}
	~Process() {
		delete [] ptFile;
	}

};