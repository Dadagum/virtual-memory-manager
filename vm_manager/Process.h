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