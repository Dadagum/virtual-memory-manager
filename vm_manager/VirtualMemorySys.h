#pragma once
#include"Address.h"
#include"PageTable.h"

/*
	虚拟内存的分页系统基类
*/
class VirtualMemorySys {
public:
	virtual void importPageTable(const char * fileName) = 0; // 从文件导入页表
	virtual void savePageTable(const char * fileName) = 0; // 导出页表内容
	virtual void request(const Address & address) = 0; // 访问某一个虚拟地址
};