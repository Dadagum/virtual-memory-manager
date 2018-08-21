#include "TwoLevelVmSys.h"
#include<cmath>

TwoLevelVmSys::TwoLevelVmSys()
{
	// ��ʼ������ҳ��
	int cnt = pow(2, SysConfig::PT1); // ����ҳ���pte����
	e1 = cnt;
	root = new PageTable(cnt);
	// ��ʼ��ָ�����ҳ���ָ��
	table2 = new PageTable*[cnt];
	cnt = pow(2, SysConfig::PT2);
	e2 = cnt;
}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram)
{
	int fNumber = 0;
	// �õ�PT1��PT2��ֵ
	int pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	int pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2);
	// �鿴����ҳ���ҵ���Ӧ��ҳ����
	if (!root->entries[pt1].present) { // ����ҳ����Ȼû�м���
		table2[pt1] = new PageTable(e2); // ���ض���ҳ���ڴ�
		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; // Ĭ�϶�Ӧ����һ��ҳ���λ��Ϊ������±�
	}
	// ��ʱ����ҳ���Ѿ����ڴ棬�鿴����ҳ���Ӧ�ı���
	int index = root->entries[pt1].number; // ȡ������ҳ�����ڵĵ�ַ/λ��
	// �鿴�Ƿ����ڴ���
	if (!table2[index]->entries[pt2].present) { // �����ڴ��У���Ҫ���ص��ڴ�
		fNumber = ram->allocate(pid, pt2);
		
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;
	}
	else { // ���ڴ���
		fNumber = table2[index]->entries[pt2].number; // ȡ��ҳ���
		ram->visit(fNumber); // ����LRU����
	}
	return fNumber;
}


