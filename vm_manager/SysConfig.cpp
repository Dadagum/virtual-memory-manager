#include"SysConfig.h"

// ��������
const int SysConfig::PROCESS = 5; // ���̵ĸ���
const int SysConfig::P_SIZE[5] = {1, 32, 64, 128, 256}; // ��Ӧ���̵Ĵ�С
const int SysConfig::P_ROUND = 3; // ��������ִ�е�����

// �ڴ�����
const int SysConfig::VA_BIT = 32; // �����ַλ��
const int SysConfig::PAGE_SIZE = 8; // ҳ���С8KB
const int SysConfig::M_SIZE = 32; // �����ڴ��С32MB

// TLB
const int SysConfig::TLB = 16; // TLB�������


// ҳ��(�������и�����ĿҪ����ö���ҳ��)
const int SysConfig::PT_LEVEL = 2;
const int SysConfig::PT1 = 9;
const int SysConfig::PT2 = 10;
const int SysConfig::OFFSET = 13; // ƫ����ռ13bit(8KB)

// �����ļ�������ģʽ
const char SysConfig::PT_FILE[] = "../outputs/page_table_i.txt"; // ������̵�ҳ����ļ�����ģʽ������"pi_pageTable.txt"
const int SysConfig::PT_FILE_I = 22; // �滻�����ļ�ģʽ�ĵ�һλi
const int SysConfig::PT_FILE_LEN = 30; // �ļ�ģʽ���Ƶĳ���

const char SysConfig::VISIT_LIST_FILE[] = "../outputs/addr_seq_i.txt"; // ����������ɵ������ַ�������е��ļ���
const int SysConfig::VL_FILE_I = 20; // �滻ģʽ���±�
const int SysConfig::VL_FILE_LEN = 30; // �ļ����Ƴ���

const char SysConfig::VISIT_INFO_FILE[] = "../outputs/visit_seq_i.txt"; // ������������ַ����Ϣ���ļ���
const int SysConfig::VI_FILE_I = 21;
const int SysConfig::VI_FILE_LEN = 30;

// �������������
const int SysConfig::RAN_LIST = 9; // ��һ����ַ���ɺ����������ɵ�ַ�ĸ���
const int SysConfig::RAN_ROUND = 50; // �����ܹ���ַ���еĴ���