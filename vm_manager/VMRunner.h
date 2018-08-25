#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"
#include"Memory.h"
#include"RequestInfo.h"
#include<list>
using namespace std;

/*
	�����
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	Memory * ram;
	list<RequestInfo> infoList;
	void request(const Address & address, int pid); // ���������ַ
public:
	VMRunner();
	~VMRunner();
	void run(); // ��ں���������������к�ִ�д�����ģ�⿪ʼ
};