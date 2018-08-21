#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"
#include"Memory.h"

/*
	�����
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	Memory * ram;
	void request(const Address & address, int pid); // ���������ַ
public:
	VMRunner(Tlb * t, Process * ps, VirtualMemorySys * v, Memory * r) {
		tlb = t;
		process = ps;
		vms = v;
		ram = r;
	}
	void run(); // ��ں���������������к�ִ�д�����ģ�⿪ʼ
};