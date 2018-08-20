#include "TwoLevelVmSys.h"

TwoLevelVmSys::TwoLevelVmSys()
{
	// 初始化顶级页表
	root = new PageTable(SysConfig::PT1);
}

int TwoLevelVmSys::request(const Address & address)
{
	// TODO
	return 0;
}


