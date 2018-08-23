#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"
#include<vector>
using namespace std;

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // 顶级页表
	PageTable ** table2; // 二级页表
	int e1; // 顶级页表的页表项数量
	int e2; // 二级页表的页表项数量
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
	// 实现父类方法
	void importPageTable(const char * fileName);
	void savePageTable(const char * fileName);
	int request(const Address & addres, int pid, Memory * ram, RequestInfo & info); // 根据虚拟地址找出页框号，如果没有那么则会分配页框和虚页，返回新分配的页框号
	int request(const Address & addres, int pid, Memory * ram);
	
};