#pragma once
#include"PageFrame.h"
#include"SysConfig.h"
#include<cmath>

/*
	�ڴ����ݽṹ
*/
class Memory {
private:
	PageFrame * pf;
	int curr; // ָ������λ��
	int capacity; // ���ɵ����ҳ������
public:
	Memory() {
		capacity = SysConfig::M_SIZE * pow(2, 10) / SysConfig::PAGE_SIZE;
		curr = 0;
		pf = new PageFrame[capacity];
	}
	~Memory() {
		delete [] pf;
	}
	void allocate(int pid, int pNumber);
	void update(int fNumber);
};