#include"VMRunner.h"
#include"RandomUtil.h"
#include"FileUtil.h"
#include"RequestInfo.h"
#include"Constant.h"

void VMRunner::request(const Address & address, int pid)
{
	RequestInfo info; // ���������Ϣ
	// ��ȡ��ַ��ȥoffset�Ĳ���
	int pNumber = address.getNumber(SysConfig::OFFSET);

	info.pNumber = pNumber; // ��¼VP number

	// ���TLB
	int fNumber = tlb->getfNumber(pNumber);
	if (fNumber == Constant::TLB_MISS) { // TLBȱʧ

		// TODO info��¼

		fNumber = vms->request(address, pid, ram); // ������в��ҵõ�ҳ���
		tlb->allocate(pNumber, fNumber); // ��¼��TLB��
	}
	else { // TLB����
		ram->visit(fNumber); // ����TLB��LRU����

		info.ptHit = true;
		info.tlbHit = true;
	}

	info.fNumber = fNumber; // ��¼ PF number
}

void VMRunner::run()
{
	for (int r = 0; r < SysConfig::P_ROUND; r++) { // ִ��round��
		for (int p = 0; p < SysConfig::PROCESS; p++) { // ����ִ��
			// �����ⲿҳ�������
			vms->importPageTable(process[p].ptFile);

			// �õ������������
			int total = 0;
			Address * addresses = RandomUtil::nextAddressList(50, total); // Ĭ��50��ѭ�����ɵ�ַ
			FileUtil::saveAddressList(addresses, total, p); // �����ʵ������ַ�������

			for (int i = 0; i < total; i++) {
				request(addresses[i], p); // ���������ַ
			}

			// ����ҳ������
			vms->savePageTable(process[p].ptFile);
			// ���TLB����
			tlb->clear();
		}
	}
}