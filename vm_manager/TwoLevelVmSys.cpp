#include "TwoLevelVmSys.h"

TwoLevelVmSys::TwoLevelVmSys()
{
	// ��ʼ������ҳ��
	root = new PageTable(SysConfig::PT1);
}

int TwoLevelVmSys::request(const Address & address)
{
	// TODO
	return 0;
}


