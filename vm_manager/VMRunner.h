#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"

/*
	入口类
*/
class VMRunner {
private:
public:
	void run(Tlb * tlb, Process * list, int size, int round); // 入口函数：传入进程序列和执行次数，模拟开始
};