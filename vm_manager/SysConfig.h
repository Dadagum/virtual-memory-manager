#pragma once

/*
	ϵͳ����
*/

class SysConfig {
public:
	// ��������
	static const int PROCESS; // ���̸���
	static const int P1_SIZE; // �������̵Ĵ�С����λMB 
	static const int P2_SIZE;
	static const int P3_SIZE;
	static const int P4_SIZE;
	static const int P5_SIZE;

	// �ڴ�����
	static const int VA_BIT; // �����ַλ��
	static const int PAGE_SIZE; // (ҳ��|ҳ��)��С����λKB

	// TLB
	static const int TLB;
};
