#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"
#include<vector>
using namespace std;

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // 顶级页表
	vector<PageTable *>  table2; // 二级页表
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
	}
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
};