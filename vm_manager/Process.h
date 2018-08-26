#pragma once
#include<iostream>
#include"TwoLevelVmSys.h"

/*
	进程
*/
class Process {
public:
	int size; // 进程大小
	int pid; // 进程标识符
	Process(int size, int id) {
		setValue(size, id);
	}
	Process() {
		size = 0;
		pid = 0;
	}
	void setValue(int size, int id) {
		this->size;
		this->pid = id;
	}
	~Process() {
	}

};