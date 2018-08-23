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
	char * ptFile; // 将页表内容保存到外部文件的文件名称
	Process(int size, int id) {
		setValue(size, id);
	}
	Process() {
		size = 0;
		pid = 0;
		ptFile = NULL;
	}
	void setValue(int size, int id) {
		this->size;
		this->pid = id;
		// 初始化ptFile
		ptFile = new char[SysConfig::PT_FILE_LEN];
		strcpy_s(ptFile, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
		ptFile[SysConfig::PT_FILE_I] = (char)(id + 48);
	}
	~Process() {
		delete [] ptFile;
	}

};