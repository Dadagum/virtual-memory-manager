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
	VirtualMemorySys * vms; // 进程页表结构
	char * ptFile; // 将页表内容保存到外部文件的文件名称
	Process(int size, VirtualMemorySys* v, int id) {
		this->size;
		vms = v;
		this->pid = id;
		// 初始化ptFile
		// TODO
	}
	void setSize(int size) {
		this->size = size;
	}
	~Process() {
		delete vms;
		delete ptFile;
	}

};