#include"SysConfig.h"

// ��������
const int SysConfig::PROCESS = 5;
const int SysConfig::P1_SIZE = 1;
const int SysConfig::P2_SIZE = 32;
const int SysConfig::P3_SIZE = 64;
const int SysConfig::P4_SIZE = 128;
const int SysConfig::P5_SIZE = 256;

// �ڴ�����
const int SysConfig::VA_BIT = 32;
const int SysConfig::PAGE_SIZE = 8;

// TLB
const int SysConfig::TLB = 16; // TLB�������
const int SysConfig::TLB_EMPTY = -1;

// ҳ��(�������и�����ĿҪ����ö���ҳ��)
const int SysConfig::PT_LEVEL = 2;
//static const int PT1;
//static const int PT2;
const int SysConfig::OFFSET = 13; // ƫ����ռ13bit

// ���й��̱����ļ�����ģʽ
char      SysConfig::PT_FILE[] = "pi_pageTable.txt"; // ������̵�ҳ����ļ�����ģʽ������"pi_pageTable.txt"
const int SysConfig::PT_FILE_I = 1; // �滻�����ļ�ģʽ�ĵ�һλi
const int SysConfig::PT_FILE_LEN = 20; // �ļ�ģʽ���Ƶĳ���