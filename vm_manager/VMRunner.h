#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"
#include"Memory.h"
#include"RequestInfo.h"
#include<list>
using namespace std;

/*
	入口类
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	Memory * ram;
	list<RequestInfo> infoList; // 访问信息序列
	int * pageFault; // 记录进程运行过程的页缺失次数
	void request(const Address & address, int pid); // 访问虚拟地址
	void printPageFault(int total); // 在控制台中打印出页缺失率
public:
	VMRunner();
	~VMRunner();
	void run(); // 入口函数：传入进程序列和执行次数，模拟开始
};