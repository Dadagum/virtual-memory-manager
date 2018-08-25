#pragma once
#include"Address.h"
#include"PageTable.h"
#include"Memory.h"
#include"RequestInfo.h"

/*
	�����ڴ�ķ�ҳϵͳ����
*/
class VirtualMemorySys {
public:
	virtual void reset() = 0; // ���ҳ������
	virtual void importPageTable(int pid, Memory * ram) = 0; // ���ļ�����ҳ��
	virtual void savePageTable(int pid) = 0; // ����ҳ������
	virtual int request(const Address & address, int pid, Memory * ram) = 0; // ���������ַ�ҳ�ҳ��ţ����û����ô������ҳ�����ҳ�������·����ҳ���
	virtual int request(const Address & address, int pid, Memory * ram, RequestInfo & info) = 0; 
};