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
	list<RequestInfo> infoList; // ������Ϣ����
	int * pageFault; // ��¼�������й��̵�ҳȱʧ����
	void request(const Address & address, int pid); // ���������ַ
	void printPageFault(int total); // �ڿ���̨�д�ӡ��ҳȱʧ��
public:
	VMRunner();
	~VMRunner();
	void run(); // ��ں���������������к�ִ�д�����ģ�⿪ʼ
};