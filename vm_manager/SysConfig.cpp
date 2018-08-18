#include"SysConfig.h"

// 进程配置
const int SysConfig::PROCESS = 5;
const int SysConfig::P1_SIZE = 1;
const int SysConfig::P2_SIZE = 32;
const int SysConfig::P3_SIZE = 64;
const int SysConfig::P4_SIZE = 128;
const int SysConfig::P5_SIZE = 256;

// 内存配置
const int SysConfig::VA_BIT = 32;
const int SysConfig::PAGE_SIZE = 8;

// TLB
const int SysConfig::TLB = 16; // TLB表项个数
const int SysConfig::TLB_EMPTY = -1;

// 页表(此例子中根据题目要求采用二级页表)
const int SysConfig::PT_LEVEL = 2;
//static const int PT1;
//static const int PT2;
const int SysConfig::OFFSET = 13; // 偏移量占13bit

// 运行过程保存文件名称模式
char      SysConfig::PT_FILE[] = "pi_pageTable.txt"; // 保存进程的页表的文件名称模式，例如"pi_pageTable.txt"
const int SysConfig::PT_FILE_I = 1; // 替换上面文件模式的第一位i
const int SysConfig::PT_FILE_LEN = 20; // 文件模式名称的长度