#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // 顶级页表
	PageTable * table2; // 二级页表
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
		delete table2;
	}
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
};