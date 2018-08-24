#include "TwoLevelVmSys.h"
#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;

void TwoLevelVmSys::init()
{
	root = new PageTable(e1);
	table2 = new PageTable*[e2];
}

TwoLevelVmSys::TwoLevelVmSys()
{
	int cnt = pow(2, SysConfig::PT1); // 顶级页表的pte数量
	e1 = cnt;
	cnt = pow(2, SysConfig::PT2); // 二级页表的pte数量
	e2 = cnt;
	init();
}

void TwoLevelVmSys::reset()
{
	delete root;
	delete[] table2;
	init();
}


void TwoLevelVmSys::savePageTable(int pid)
{
	// 保存的文件名称
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy(fileName, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// 写入文件
	ofstream fout(fileName, ios::out | ios::binary );
	// 写入顶级页表
	fout.write((char *)&root->address, sizeof root->address); // 写入顶级页表的地址
	fout.write((char *)&root->size, sizeof root->size); // 写入顶级页表项的数量
	for (int i = 0; i < e1; i++) fout.write((char *)&root->entries[i], sizeof root->entries[i]);// 写入顶级页表的全部页表项
	// 写入二级页表
	for (int i = 0; i < e1; i++) {
		if (root->entries[i].present) { // 二级页表在内存中，需要记录
			fout.write((char *)&table2[i]->address, sizeof table2[i]->address); // 写入二级页表的地址
			fout.write((char *)&table2[i]->size, sizeof table2[i]->size); // 写入二级页表项的数量
			for (int j = 0; j < e2; j++) fout.write((char *)&table2[i]->entries[j], sizeof table2[i]->entries[j]);// 写入二级页表的全部页表项
		}
	}

	fout.close();

}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram, RequestInfo & info)
{
	int fNumber = 0;
	// 得到PT1，PT2的值
	int pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	int pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2);
	// 查看顶级页表，找到对应的页表项
	if (!root->entries[pt1].present) { // 二级页表仍然没有加载
		table2[pt1] = new PageTable(e2, pt1); // 加载二级页表到内存

		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; 
	}
	// 此时二级页表已经在内存，查看二级页表对应的表项
	int index = root->entries[pt1].number; // 取出二级页表所在的地址/位置
	// 查看是否在内存中
	if (!table2[index]->entries[pt2].present) { // 不在内存中，需要加载到内存

		PageFrame frame(pid);
		fNumber = ram->allocate(frame); // 分配新的页框到内存中
		
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;

		info.ptHit = false; // 缺失消息记录
	}
	else { // 在内存中
		fNumber = table2[index]->entries[pt2].number; // 取出页框号
		ram->visit(fNumber); // 更新LRU序列

		info.ptHit = true;  // 命中消息记录
	}
	return fNumber;
}

int TwoLevelVmSys::request(const Address & addres, int pid, Memory * ram)
{
	return 0;
}


