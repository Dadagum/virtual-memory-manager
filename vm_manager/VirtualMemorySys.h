#pragma once
#include"Address.h"
#include"PageTable.h"
#include"Memory.h"
#include"RequestInfo.h"

/*
	虚拟内存的分页系统基类
*/
class VirtualMemorySys {
public:
	virtual void reset() = 0; // 清空页表内容
	virtual void importPageTable(int pid, Memory * ram) = 0; // 从文件导入页表
	virtual void savePageTable(int pid) = 0; // 导出页表内容
	virtual int request(const Address & address, int pid, Memory * ram) = 0; // 根据虚拟地址找出页框号，如果没有那么则会分配页框和虚页，返回新分配的页框号
	virtual int request(const Address & address, int pid, Memory * ram, RequestInfo & info) = 0; 
};