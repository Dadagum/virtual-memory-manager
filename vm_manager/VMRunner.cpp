#include"VMRunner.h"
#include"RandomUtil.h"

void VMRunner::request(const Address & address)
{
	// ��ȡ��ַ��ȥoffset�Ĳ���
	int pNumber = address.getNumber(SysConfig::OFFSET);
	// ���TLB
	int fNumber = tlb->getfNumber(pNumber);
	if (fNumber == SysConfig::TLB_MISS) { // TLBȱʧ
		fNumber = vms->request(address); // ������в��ҵõ�ҳ���
		tlb->allocate(pNumber, fNumber); // ��¼��TLB��
	}
	else { // TLB����
		ram->visit(fNumber); // �����ڴ�
	}
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

			for (int i = 0; i < total; i++) {
				request(addresses[i]); // ���������ַ
			}

			// ����ҳ������
			vms->savePageTable(process[p].ptFile);
			// ���TLB����
			tlb->clear();
		}
	}
}