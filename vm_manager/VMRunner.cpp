#include "VMRunner.h"

void VMRunner::run(Tlb * tlb, Process * list, int size, int round)
{
	for (int r = 0; r < round; r++) {
		// �����ⲿҳ�������
		list[r].vms->importPageTable(list[r].ptFile);

		// ���Ĵ��벿�� TODO

		// ����ҳ������
		list[r].vms->savePageTable(list[r].ptFile);
		// ���TLB����
		tlb->clear();
	}
}