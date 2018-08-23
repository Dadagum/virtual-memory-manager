#include"VMRunner.h"
#include"RandomUtil.h"
#include"FileUtil.h"
#include"RequestInfo.h"
#include"Constant.h"
#include"TwoLevelVmSys.h"
#include"Memory"


VMRunner::VMRunner()
{
	// ������Ŀ��ʼ��
	tlb = new Tlb(SysConfig::TLB); // tlb
	process = new Process[5]; // process
	for (int i = 0; i < SysConfig::PROCESS; i++) process[i].setValue(SysConfig::P_SIZE[i], i+1);
	vms = new TwoLevelVmSys; // vms
	ram = new Memory; // ram
}

VMRunner::~VMRunner()
{
	delete tlb;
	delete[] process;
	delete vms;
	delete ram;
}

void VMRunner::request(const Address & address, int pid)
{
	RequestInfo info; // ���������Ϣ
	// ��ȡ��ַ��ȥoffset�Ĳ���
	int pNumber = address.getNumber(SysConfig::OFFSET);

	info.pNumber = pNumber; // ��¼VP number

	// ���TLB
	int fNumber = tlb->getfNumber(pNumber);
	if (fNumber == Constant::TLB_MISS) { // TLBȱʧ

		info.tlbHit = false;

		fNumber = vms->request(address, pid, ram); // ������в��ҵõ�ҳ���
		tlb->allocate(pNumber, fNumber); // ��¼��TLB��
	}
	else { // TLB����
		ram->visit(fNumber); // �����ڴ��LRU����

		info.ptHit = true; // ��¼TLB,PT�������
		info.tlbHit = true;
	}

	info.fNumber = fNumber; // ��¼ PF number
	// ��infoд���ļ�
}

void VMRunner::run()
{
	RandomUtil random;
	for (int r = 0; r < SysConfig::P_ROUND; r++) { // ִ��round��
		for (int p = 0; p < SysConfig::PROCESS; p++) { // ����ִ��
			// �����ⲿҳ�������
			vms->importPageTable(process[p].ptFile);

			// �õ������������
			int total = 0;
			Address * addresses = random.nextAddressList(50, total, SysConfig::P_SIZE[p]); // Ĭ��50��ѭ�����ɵ�ַ
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