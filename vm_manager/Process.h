#pragma once
#include<iostream>
#include"TwoLevelVmSys.h"

/*
	����
*/
class Process {
private:
	int size; // ���̴�С
	int pid; // ���̱�ʶ��
public:
	char * ptFile; // ��ҳ�����ݱ��浽�ⲿ�ļ����ļ�����
	Process(int size, int id) {
		this->size;
		this->pid = id;
		// ��ʼ��ptFile
		// TODO
	}
	void setSize(int size) {
		this->size = size;
	}
	~Process() {
		delete [] ptFile;
	}

};