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
	VirtualMemorySys * vms; // ����ҳ��ṹ
	char * ptFile; // ��ҳ�����ݱ��浽�ⲿ�ļ����ļ�����
	Process(int size, VirtualMemorySys* v, int id) {
		this->size;
		vms = v;
		this->pid = id;
		// ��ʼ��ptFile
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