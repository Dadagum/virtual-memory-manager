#include "TwoLevelVmSys.h"

TwoLevelVmSys::TwoLevelVmSys()
{
	// ��ʼ������ҳ��
	root = new PageTable(SysConfig::PT1);
	// ��ʼ������ҳ��
	table2 = new PageTable[SysConfig::PT1];
	for (int i = 0; i < SysConfig::PT1; i++) {
		table2[i].setValue(SysConfig::PT2);
	}
}

// ���ļ��е���ҳ����Ϣ
void TwoLevelVmSys::importPageTable(const char * fileName)
{
}

// ����ҳ���ļ�
void TwoLevelVmSys::savePageTable(const char * fileName)
{
}
