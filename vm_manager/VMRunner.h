#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"
#include"Memory.h"

/*
	入口类
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	Memory * ram;
	void request(const Address & address, int pid); // 访问虚拟地址
public:
	VMRunner();
	~VMRunner();
	void run(); // 入口函数：传入进程序列和执行次数，模拟开始
};