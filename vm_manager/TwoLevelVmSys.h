#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"
#include<vector>
using namespace std;

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // ����ҳ��
	vector<PageTable>  table2; // ����ҳ��
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
	}
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
	int request(const Address & address); // ���������ַ�ҳ�ҳ��ţ����û����ô������ҳ�����ҳ�������·����ҳ���
};