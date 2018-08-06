#pragma once

/*
	系统配置
*/

class SysConfig {
public:
	// 进程配置
	static const int PROCESS; // 进程个数
	static const int P1_SIZE; // 各个进程的大小，单位MB 
	static const int P2_SIZE;
	static const int P3_SIZE;
	static const int P4_SIZE;
	static const int P5_SIZE;

	// 内存配置
	static const int VA_BIT; // 虚拟地址位长
	static const int PAGE_SIZE; // (页面|页框)大小，单位KB

	// TLB
	static const int TLB;
};
