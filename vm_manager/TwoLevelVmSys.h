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

	void init(); // 初始化，cnt为页表的entry数量
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
		delete [] table2;
	}
	void reset(); // 重置页表内容

	// 实现父类方法
	void importPageTable(int pid, Memory * ram); // 从外部文件导入页表
	void savePageTable(int pid); // 将当前进程的页表保存到文件中
	int request(const Address & addres, int pid, Memory * ram, RequestInfo & info); // 根据虚拟地址找出页框号，如果没有那么则会分配页框和虚页，返回新分配的页框号
	int request(const Address & addres, int pid, Memory * ram);
	void recordPageTableTxt(int pid); // 为了方便显示页表的内容，在运行结束后将页表内容导出到txt文件中
};