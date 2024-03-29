#include "TwoLevelVmSys.h"
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void TwoLevelVmSys::init()
{
	root = new PageTable(e1);
	table2 = new PageTable*[e1];
	for (int i = 0; i < e1; i++) table2[i] = nullptr;
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
	for (int i = 0; i < e1; i++) {
		delete table2[i];
		table2[i] = nullptr;
	}
	root = new PageTable(e1);
}


void TwoLevelVmSys::importPageTable(int pid, Memory * ram)
{
	// 重置页表
	reset();

	// 页表存放文件
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	ifstream fin(fileName, ios::in | ios::binary);

	if (fin.is_open()){
		// 读取顶级页表
		for (int i = 0; i < e1; i++) {
			fin.read((char *)&root->entries[i], sizeof root->entries[i]);
		}
		// 读取二级页表
		int index; // 二级页表所在位置
		while (fin.read((char *)&index, sizeof index)) {
			// 加载恢复二级页表
			table2[index] = new PageTable(e2);
			fin.read((char *)&table2[index]->used, sizeof table2[index]->used);
			// 读取二级页表的页表项
			for (int i = 0; i < e2; i++) fin.read((char *)&table2[index]->entries[i], sizeof table2[index]->entries[i]);

			// 恢复顶级页表的相关表项
			root->entries[index].present = true;
			root->entries[index].number = index;
			root->used++;
			
		}
	}
	fin.close();

	// 检查是否有页框已经被其它进程置换
	while (!ram->cache->isEmpty(pid)) {
		PageFrame tmp = ram->cache->pop(pid); // 已经被置换出的页面

		unsigned pt1 = tmp.getVa().getNumber(SysConfig::OFFSET + SysConfig::PT2);
		unsigned pt2 = tmp.getVa().getNumber(SysConfig::OFFSET, SysConfig::PT2 + SysConfig::OFFSET);

		cout << "更新进程 pid = " << dec << pid << "的页表 : " << " 虚拟页号为 " << tmp.getVa().value << " 所对应的页框被其它进程替换 " << endl;

		// 该页表项无效
		table2[pt1]->entries[pt2].present = false;
		table2[pt1]->used--;

		if (table2[pt1]->used == 0) { // 二级页表为空
			delete table2[pt1]; 
			root->entries[pt1].present = false;
		}
	}


}

void TwoLevelVmSys::savePageTable(int pid)
{
	// 保存的文件名称
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// 写入文件
	ofstream fout(fileName, ios::out | ios::binary );
	if (fout.is_open()) {
		// 写入顶级页表
		for (int i = 0; i < e1; i++) {
			fout.write((char *)&root->entries[i], sizeof root->entries[i]);// 写入顶级页表的全部页表项
		}

		// 写入二级页表
		for (int i = 0; i < e1; i++) {
			if (root->entries[i].present) { // 二级页表在内存中，需要写入文件
				fout.write((char *)&i, sizeof i); // 写入二级页表的地址，实际上是数组下标，方便导入文件时恢复页表结构
				fout.write((char *)&table2[i]->used, sizeof table2[i]->used); // 写入二级页表中的有效使用的页表项数量
				for (int j = 0; j < e2; j++) {
					fout.write((char *)&table2[i]->entries[j], sizeof table2[i]->entries[j]); // 写入二级页表的全部页表项
				}
			}
		}
	}

	fout.close();
}

void TwoLevelVmSys::recordPageTableTxt(int pid)
{
	// 保存的文件名称
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// 写入文件
	ofstream fout(fileName, ios::out);
	if (fout.is_open()) {
		fout << "---------- 顶级页表部分 ----------" << endl;
		// 写入顶级页表
		for (int i = 0; i < e1; i++) {
			if(root->entries[i].present) fout << "第" << i << "项 : 二级页表的地址 = " << root->entries[i].number << ", 有效位 = " << root->entries[i].present << endl;
		}

		fout << "---------- 二级页表部分 ----------" << endl;

		// 写入二级页表
		for (int i = 0; i < e1; i++) {
			if (root->entries[i].present) { // 二级页表在内存中，需要写入文件 
				fout << "二级页表地址 = " << i << " : ----------" << endl;
				for (int j = 0; j < e2; j++) {
					if (table2[i]->entries[j].present) fout << "第" << j << "项 : 页框号 = " << table2[i]->entries[j].number << ", 有效位 = " << table2[i]->entries[j].present << endl;
				}
			}
		}
	}

	fout.close();
}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram, RequestInfo & info)
{
	unsigned fNumber = 0;
	// 得到PT1，PT2的值
	unsigned pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	unsigned pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2 + SysConfig::OFFSET);
	// 查看顶级页表，找到对应的页表项
	if (!root->entries[pt1].present) { // 二级页表仍然没有加载
		table2[pt1] = new PageTable(e2); // 加载二级页表到内存

		// 更新顶级页表信息
		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; 
		root->used++;
	}
	// 此时二级页表已经在内存，查看二级页表对应的表项
	unsigned index = root->entries[pt1].number; // 取出二级页表所在的地址/位置
	// 查看是否在内存中
	if (!table2[index]->entries[pt2].present) { // 不在内存中，需要加载到内存 

		PageFrame frame(pid, address);
		fNumber = ram->allocate(frame); // 分配新的页框到内存中
		
		// 更新二级页表信息
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;
		table2[index]->used++;

		info.ptHit = false; // 缺失消息记录
	}
	else { // 在内存中
		fNumber = table2[index]->entries[pt2].number; // 取出页框号
		ram->visit(fNumber); // 更新LRU序列

		info.ptHit = true;  // 命中消息记录
	}
	return fNumber;
}

