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
	virtual void request(const Address & address) = 0; // ����ĳһ�������ַ
};