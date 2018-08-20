#pragma once
#include"Address.h"
#include"PageTable.h"

/*
	�����ڴ�ķ�ҳϵͳ����
*/
class VirtualMemorySys {
public:
	virtual void importPageTable(const char * fileName) = 0; // ���ļ�����ҳ��
	virtual void savePageTable(const char * fileName) = 0; // ����ҳ������
	virtual int request(const Address & address) = 0; // ���������ַ�ҳ�ҳ��ţ����û����ô������ҳ�����ҳ�������·����ҳ���
};