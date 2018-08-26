#include"VMRunner.h"
#include"RandomUtil.h"
#include"Constant.h"
#include"TwoLevelVmSys.h"
#include"Memory"
#include"Logger.h"

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

		fNumber = vms->request(address, pid, ram, info); // ������в��ҵõ�ҳ���
		TlbEntry entry(pNumber, fNumber);
		tlb->allocate(entry); // ��¼��TLB��
	}
	else { // TLB����
		ram->visit(fNumber); // �����ڴ��LRU����

		// ��¼TLB,PT�������
		info.ptHit = true; 
		info.tlbHit = true;
	}

	// ��¼info
	info.fNumber = fNumber; // ��¼ PF number
	infoList.push_back(info); // ����β��
}

void VMRunner::run()
{
	RandomUtil random;
	for (int r = 0; r < SysConfig::P_ROUND; r++) { // ִ��round��
		for (int p = 1; p < SysConfig::PROCESS; p++) { // ����ִ�� // test : p��1��ʼ
			// �����ⲿҳ�������
			vms->importPageTable(p, ram);

			// �õ������������
			int total = 0;
			Address * addresses = random.nextAddressList(50, total, SysConfig::P_SIZE[p]); // Ĭ��50��ѭ�����ɵ�ַ
			Logger::saveAddressList(addresses, total, p); // �����ʵ������ַ�������

			for (int i = 0; i < total; i++) {
				request(addresses[i], p); // ���������ַ
			}

			// ����ҳ������
			vms->savePageTable(p);
			// ���TLB����
			tlb->clear();
			// ����������Ϣ���ļ���
			Logger::saveRequestInfo(infoList, 500, p);
		}
	}

}