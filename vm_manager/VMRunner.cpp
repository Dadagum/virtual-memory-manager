#include "VMRunner.h"

void VMRunner::run(Tlb * tlb, Process * list, int size, int round)
{
	for (int r = 0; r < round; r++) {
		// 导入外部页表的内容
		list[r].vms->importPageTable(list[r].ptFile);

		// 核心代码部分 TODO

		// 导出页表内容
		list[r].vms->savePageTable(list[r].ptFile);
		// 清空TLB内容
		tlb->clear();
	}
}