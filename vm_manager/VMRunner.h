#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"

/*
	�����
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	void request(const Address & address); // ����ĳһ�������ַ 
public:
	VMRunner(Tlb * t, Process * ps, VirtualMemorySys * v) {
		tlb = t;
		process = ps;
		vms = v;
	}
	void run(); // ��ں���������������к�ִ�д�����ģ�⿪ʼ
};