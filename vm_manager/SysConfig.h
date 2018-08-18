#pragma once
#include<string>

/*
	根据题目要求的系统配置
*/

class SysConfig {
public:
	// 进程
	static const int PROCESS; // 进程个数
	static const int P1_SIZE; // 各个进程的大小，单位MB 
	static const int P2_SIZE;
	static const int P3_SIZE;
	static const int P4_SIZE;
	static const int P5_SIZE;

	// 内存
	static const int VA_BIT; // 虚拟地址位长
	static const int PAGE_SIZE; // (页面|页框)大小，单位KB
	static const int M_SIZE; // 物理内存大小，单位MB

	// TLB
	static const int TLB; // TLB项数量
	static const int TLB_EMPTY; // 当TLB表项没有内容时，表项的虚页号和叶框号都会置为此值

	// 页表(此例子中根据题目要求采用二级页表)
	static const int PT_LEVEL; 
	static const int PT1; // 划分顶级页表
	static const int PT2; // 划分二级页表
	static const int OFFSET; // 页内偏移量

	// 运行过程保存文件名称模式
	static char PT_FILE[]; // 保存进程的页表的文件名称模式，例如"pi_pageTable.txt"
	static const int PT_FILE_I; // 替换模式的下标
	static const int PT_FILE_LEN; // 文件名称的长度
};
