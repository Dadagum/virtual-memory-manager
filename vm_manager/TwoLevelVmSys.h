#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // ����ҳ��
	PageTable * table2; // ����ҳ��
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
		delete table2;
	}
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
};