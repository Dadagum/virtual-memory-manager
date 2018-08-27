#pragma once
#include"VirtualMemorySys.h"
#include"SysConfig.h"
#include<vector>
using namespace std;

class TwoLevelVmSys : public VirtualMemorySys {
private:
	PageTable * root; // ����ҳ��
	PageTable ** table2; // ����ҳ��
	int e1; // ����ҳ���ҳ��������
	int e2; // ����ҳ���ҳ��������

	void init(); // ��ʼ����cntΪҳ���entry����
public:
	TwoLevelVmSys();
	~TwoLevelVmSys() {
		delete root;
		delete [] table2;
	}
	void reset(); // ����ҳ������

	// ʵ�ָ��෽��
	void importPageTable(int pid, Memory * ram); // ���ⲿ�ļ�����ҳ��
	void savePageTable(int pid); // ����ǰ���̵�ҳ���浽�ļ���
	int request(const Address & addres, int pid, Memory * ram, RequestInfo & info); // ���������ַ�ҳ�ҳ��ţ����û����ô������ҳ�����ҳ�������·����ҳ���
	int request(const Address & addres, int pid, Memory * ram);
	void recordPageTableTxt(int pid); // Ϊ�˷�����ʾҳ������ݣ������н�����ҳ�����ݵ�����txt�ļ���
};