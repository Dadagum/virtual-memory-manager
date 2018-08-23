#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"
#include<vector>
using namespace std;

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // ����ҳ��
	PageTable ** table2; // ����ҳ��
	int e1; // ����ҳ���ҳ��������
	int e2; // ����ҳ���ҳ��������
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
		delete [] table2;
	}
	void clear() {
		delete root;
		delete [] table2;
		root = NULL;
		table2 = NULL;
	}
	// ʵ�ָ��෽��
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
	int request(const Address & addres, int pid, Memory * ram, RequestInfo & info); // ���������ַ�ҳ�ҳ��ţ����û����ô������ҳ�����ҳ�������·����ҳ���
	int request(const Address & addres, int pid, Memory * ram);
	
};