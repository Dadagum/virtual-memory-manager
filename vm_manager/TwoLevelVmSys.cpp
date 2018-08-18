#include "TwoLevelVmSys.h"

TwoLevelVmSys::TwoLevelVmSys()
{
	// 初始化顶级页表
	root = new PageTable(SysConfig::PT1);
	// 初始化二级页表
	table2 = new PageTable[SysConfig::PT1];
	for (int i = 0; i < SysConfig::PT1; i++) {
		table2[i].setValue(SysConfig::PT2);
	}
}

// 从文件中导入页表信息
void TwoLevelVmSys::importPageTable(const char * fileName)
{
}

// 导出页表到文件
void TwoLevelVmSys::savePageTable(const char * fileName)
{
}
