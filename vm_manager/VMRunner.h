#pragma once
#include"VirtualMemorySys.h"
#include"Process.h"
#include"Tlb.h"

/*
	�����
*/
class VMRunner {
private:
public:
	void run(Tlb * tlb, Process * list, int size, int round); // ��ں���������������к�ִ�д�����ģ�⿪ʼ
};