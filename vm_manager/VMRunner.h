#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"

/*
	入口类
*/
class VMRunner {
private:
	Tlb * tlb;
	Process * process;
	VirtualMemorySys * vms;
	void request(const Address & address); // 访问某一个虚拟地址 
public:
	VMRunner(Tlb * t, Process * ps, VirtualMemorySys * v) {
		tlb = t;
		process = ps;
		vms = v;
	}
	void run(); // 入口函数：传入进程序列和执行次数，模拟开始
};