#include"VMRunner.h"
#include"RandomUtil.h"
#include"FileUtil.h"
#include"RequestInfo.h"
#include"Constant.h"

void VMRunner::request(const Address & address, int pid)
{
	RequestInfo info; // 储存访问信息
	// 提取地址除去offset的部分
	int pNumber = address.getNumber(SysConfig::OFFSET);

	info.pNumber = pNumber; // 记录VP number

	// 检查TLB
	int fNumber = tlb->getfNumber(pNumber);
	if (fNumber == Constant::TLB_MISS) { // TLB缺失

		// TODO info记录

		fNumber = vms->request(address, pid, ram); // 在虚存中查找得到页框号
		tlb->allocate(pNumber, fNumber); // 记录在TLB中
	}
	else { // TLB命中
		ram->visit(fNumber); // 更新TLB的LRU队列

		info.ptHit = true;
		info.tlbHit = true;
	}

	info.fNumber = fNumber; // 记录 PF number
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
			FileUtil::saveAddressList(addresses, total, p); // 将访问的虚拟地址输出保存

			for (int i = 0; i < total; i++) {
				request(addresses[i], p); // 访问虚拟地址
			}

			// 导出页表内容
			vms->savePageTable(process[p].ptFile);
			// 清空TLB内容
			tlb->clear();
		}
	}
}