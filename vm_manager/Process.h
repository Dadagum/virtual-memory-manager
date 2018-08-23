#pragma once
#include<iostream>
#include"TwoLevelVmSys.h"

/*
	����
*/
class Process {
public:
	int size; // ���̴�С
	int pid; // ���̱�ʶ��
	char * ptFile; // ��ҳ�����ݱ��浽�ⲿ�ļ����ļ�����
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
		// ��ʼ��ptFile
		ptFile = new char[SysConfig::PT_FILE_LEN];
		strcpy_s(ptFile, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
		ptFile[SysConfig::PT_FILE_I] = (char)(id + 48);
	}
	~Process() {
		delete [] ptFile;
	}

};