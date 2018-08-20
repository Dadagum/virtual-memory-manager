#include"VMRunner.h"
#include"RandomUtil.h"

void VMRunner::request(const Address & address)
{
	// 提取地址除去offset的部分
	int pNumber = address.getNumber(SysConfig::OFFSET);
	// 检查TLB
	int fNumber = tlb->getfNumber(pNumber);
	if (fNumber == SysConfig::TLB_MISS) { // TLB缺失

	}
	else { // TLB命中
		tlb->update(pNumber); // 更新TLB记录

	}
}

void VMRunner::run()
{
	for (int r = 0; r < SysConfig::P_ROUND; r++) { // 执行round轮
		for (int p = 0; p < SysConfig::PROCESS; p++) { // 轮流执行
			// 导入外部页表的内容
			vms->importPageTable(process[p].ptFile);

			// 得到随机生成序列
			int total = 0;
			Address * addresses = RandomUtil::nextAddressList(50, total); // 默认50次循环生成地址

			for (int i = 0; i < total; i++) {
				vms->request(addresses[i]); // 访问虚拟地址
			}

			// 导出页表内容
			vms->savePageTable(process[p].ptFile);
			// 清空TLB内容
			tlb->clear();
		}
	}
}