#include "TwoLevelVmSys.h"

TwoLevelVmSys::TwoLevelVmSys()
{
	// ��ʼ������ҳ��
	root = new PageTable(SysConfig::PT1);
}


