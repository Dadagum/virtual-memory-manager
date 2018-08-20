#pragma once
#include<string>

/*
	������ĿҪ���ϵͳ���ú�һЩ��������
*/

class SysConfig {
public:
	// ����
	static const int PROCESS; // ���̸���
	static const int P1_SIZE; // �������̵Ĵ�С����λMB 
	static const int P2_SIZE;
	static const int P3_SIZE;
	static const int P4_SIZE;
	static const int P5_SIZE;
	static const int P_ROUND; // ��������ִ�еĴ���

	// �ڴ�
	static const int VA_BIT; // �����ַλ��
	static const int PAGE_SIZE; // (ҳ��|ҳ��)��С����λKB
	static const int M_SIZE; // �����ڴ��С����λMB

	// TLB
	static const int TLB; // TLB������
	static const int TLBE_EMPTY; // ��TLB����û������ʱ���������ҳ�ź�Ҷ��Ŷ�����Ϊ��ֵ
	static const int TLB_MISS; // TLBû��ĳһ�������ַ�ļ�¼

	// ҳ��(�������и�����ĿҪ����ö���ҳ��)
	static const int PT_LEVEL; 
	static const int PT1; // ���ֶ���ҳ��
	static const int PT2; // ���ֶ���ҳ��
	static const int OFFSET; // ҳ��ƫ����

	// �����ļ�������ģʽ
	static char PT_FILE[]; // ������̵�ҳ����ļ�����ģʽ������"pi_pageTable.txt"
	static const int PT_FILE_I; // �滻ģʽ���±�
	static const int PT_FILE_LEN; // �ļ����Ƶĳ���

	static char	VISIT_LIST_FILE[]; // ����������ɵ������ַ�������е��ļ���
	static const int VL_FILE_I; // �滻ģʽ���±�
	static const int VL_FILE_LEN; // �ļ����Ƴ���

	static char VISIT_INFO_FILE[]; // ������������ַ����Ϣ���ļ���
	static const int VI_FILE_I; 
	static const int VI_FILE_LEN;

	// �������������
	static const int RAN_LIST; // ��һ����ַ���ɺ����������ɵ�ַ�ĸ���
	static const int RAN_ROUND; // �����ܹ���ַ���еĴ���

};
