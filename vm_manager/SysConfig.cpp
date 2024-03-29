#include"SysConfig.h"

// 进程配置
const int SysConfig::PROCESS = 5; // 进程的个数
const int SysConfig::P_SIZE[5] = {1, 32, 64, 128, 256}; // 对应进程的大小
const int SysConfig::P_ROUND = 3; // 进程轮流执行的轮数

// 内存配置
const int SysConfig::VA_BIT = 32; // 虚拟地址位长
const int SysConfig::PAGE_SIZE = 8; // 页面大小8KB
const int SysConfig::M_SIZE = 32; // 物理内存大小32MB

// TLB
const int SysConfig::TLB = 16; // TLB表项个数


// 页表(此例子中根据题目要求采用二级页表)
const int SysConfig::PT_LEVEL = 2;
const int SysConfig::PT1 = 9;
const int SysConfig::PT2 = 10;
const int SysConfig::OFFSET = 13; // 偏移量占13bit(8KB)

// 操作文件的名称模式
const char SysConfig::PT_FILE[] = "../outputs/page_table_i.txt"; // 保存进程的页表的文件名称模式，例如"pi_pageTable.txt"
const int SysConfig::PT_FILE_I = 22; // 替换上面文件模式的第一位i
const int SysConfig::PT_FILE_LEN = 30; // 文件模式名称的长度

const char SysConfig::VISIT_LIST_FILE[] = "../outputs/addr_seq_i.txt"; // 保存随机生成的虚拟地址访问序列的文件名
const int SysConfig::VL_FILE_I = 20; // 替换模式的下标
const int SysConfig::VL_FILE_LEN = 30; // 文件名称长度

const char SysConfig::VISIT_INFO_FILE[] = "../outputs/visit_seq_i.txt"; // 保存访问虚拟地址的信息的文件名
const int SysConfig::VI_FILE_I = 21;
const int SysConfig::VI_FILE_LEN = 30;

// 随机数生成配置
const int SysConfig::RAN_LIST = 9; // 第一个地址生成后再连续生成地址的个数
const int SysConfig::RAN_ROUND = 50; // 生成总共地址序列的次数