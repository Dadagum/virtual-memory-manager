#pragma once
#include<string>

/*
	根据题目要求的系统配置和一些常量定义
*/

class SysConfig {
public:
	// 进程
	static const int PROCESS; // 进程个数
	static const int P_SIZE[5]; // 进程的大小，单位MB 
	static const int P_ROUND; // 进程轮流执行的次数

	// 内存
	static const int VA_BIT; // 虚拟地址位长
	static const int PAGE_SIZE; // (页面|页框)大小，单位KB
	static const int M_SIZE; // 物理内存大小，单位MB

	// TLB
	static const int TLB; // TLB项数量

	// 页表(此例子中根据题目要求采用二级页表)
	static const int PT_LEVEL; 
	static const int PT1; // 划分顶级页表
	static const int PT2; // 划分二级页表
	static const int OFFSET; // 页内偏移量

	// 操作文件的名称模式
	static const char PT_FILE[]; // 保存进程的页表的文件名称模式
	static const int PT_FILE_I; // 替换模式的下标
	static const int PT_FILE_LEN; // 文件名称的长度

	static const char	VISIT_LIST_FILE[]; // 保存随机生成的虚拟地址访问序列的文件名
	static const int VL_FILE_I; // 替换模式的下标
	static const int VL_FILE_LEN; // 文件名称长度

	static const char VISIT_INFO_FILE[]; // 保存访问虚拟地址的信息的文件名
	static const int VI_FILE_I; 
	static const int VI_FILE_LEN;

	// 随机数生成配置
	static const int RAN_LIST; // 第一个地址生成后再连续生成地址的个数
	static const int RAN_ROUND; // 生成总共地址序列的次数

};
