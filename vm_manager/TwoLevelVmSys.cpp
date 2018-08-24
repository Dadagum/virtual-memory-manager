#include "TwoLevelVmSys.h"
#include<cmath>
#include<iostream>
#include<fstream>
using namespace std;

void TwoLevelVmSys::init()
{
	root = new PageTable(e1);
	table2 = new PageTable*[e2];
}

TwoLevelVmSys::TwoLevelVmSys()
{
	int cnt = pow(2, SysConfig::PT1); // ����ҳ���pte����
	e1 = cnt;
	cnt = pow(2, SysConfig::PT2); // ����ҳ���pte����
	e2 = cnt;
	init();
}

void TwoLevelVmSys::reset()
{
	delete root;
	delete[] table2;
	init();
}


void TwoLevelVmSys::savePageTable(int pid)
{
	// ������ļ�����
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy(fileName, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// д���ļ�
	ofstream fout(fileName, ios::out | ios::binary );
	// д�붥��ҳ��
	fout.write((char *)&root->address, sizeof root->address); // д�붥��ҳ��ĵ�ַ
	fout.write((char *)&root->size, sizeof root->size); // д�붥��ҳ���������
	for (int i = 0; i < e1; i++) fout.write((char *)&root->entries[i], sizeof root->entries[i]);// д�붥��ҳ���ȫ��ҳ����
	// д�����ҳ��
	for (int i = 0; i < e1; i++) {
		if (root->entries[i].present) { // ����ҳ�����ڴ��У���Ҫ��¼
			fout.write((char *)&table2[i]->address, sizeof table2[i]->address); // д�����ҳ��ĵ�ַ
			fout.write((char *)&table2[i]->size, sizeof table2[i]->size); // д�����ҳ���������
			for (int j = 0; j < e2; j++) fout.write((char *)&table2[i]->entries[j], sizeof table2[i]->entries[j]);// д�����ҳ���ȫ��ҳ����
		}
	}

	fout.close();

}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram, RequestInfo & info)
{
	int fNumber = 0;
	// �õ�PT1��PT2��ֵ
	int pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	int pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2);
	// �鿴����ҳ���ҵ���Ӧ��ҳ����
	if (!root->entries[pt1].present) { // ����ҳ����Ȼû�м���
		table2[pt1] = new PageTable(e2, pt1); // ���ض���ҳ���ڴ�

		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; 
	}
	// ��ʱ����ҳ���Ѿ����ڴ棬�鿴����ҳ���Ӧ�ı���
	int index = root->entries[pt1].number; // ȡ������ҳ�����ڵĵ�ַ/λ��
	// �鿴�Ƿ����ڴ���
	if (!table2[index]->entries[pt2].present) { // �����ڴ��У���Ҫ���ص��ڴ�

		PageFrame frame(pid);
		fNumber = ram->allocate(frame); // �����µ�ҳ���ڴ���
		
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;

		info.ptHit = false; // ȱʧ��Ϣ��¼
	}
	else { // ���ڴ���
		fNumber = table2[index]->entries[pt2].number; // ȡ��ҳ���
		ram->visit(fNumber); // ����LRU����

		info.ptHit = true;  // ������Ϣ��¼
	}
	return fNumber;
}

int TwoLevelVmSys::request(const Address & addres, int pid, Memory * ram)
{
	return 0;
}


