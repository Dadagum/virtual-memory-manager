#include "TwoLevelVmSys.h"
#include<cmath>

TwoLevelVmSys::TwoLevelVmSys()
{
	// 初始化顶级页表
	int cnt = pow(2, SysConfig::PT1); // 顶级页表的pte数量
	e1 = cnt;
	root = new PageTable(cnt);
	// 初始化指向二级页表的指针
	table2 = new PageTable*[cnt];
	cnt = pow(2, SysConfig::PT2);
	e2 = cnt;
}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram)
{
	int fNumber = 0;
	// 得到PT1，PT2的值
	int pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	int pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2);
	// 查看顶级页表，找到对应的页表项
	if (!root->entries[pt1].present) { // 二级页表仍然没有加载
		table2[pt1] = new PageTable(e2); // 加载二级页表到内存
		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; // 默认对应的下一级页表的位置为数组的下标
	}
	// 此时二级页表已经在内存，查看二级页表对应的表项
	int index = root->entries[pt1].number; // 取出二级页表所在的地址/位置
	// 查看是否在内存中
	if (!table2[index]->entries[pt2].present) { // 不在内存中，需要加载到内存
		fNumber = ram->allocate(pid, pt2);
		
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;
	}
	else { // 在内存中
		fNumber = table2[index]->entries[pt2].number; // 取出页框号
		ram->visit(fNumber); // 更新LRU序列
	}
	return fNumber;
}


