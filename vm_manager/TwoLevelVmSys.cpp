#include "TwoLevelVmSys.h"
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void TwoLevelVmSys::init()
{
	root = new PageTable(e1);
	table2 = new PageTable*[e1];
	for (int i = 0; i < e1; i++) table2[i] = nullptr;
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
	for (int i = 0; i < e1; i++) {
		delete table2[i];
		table2[i] = nullptr;
	}
	root = new PageTable(e1);
}


void TwoLevelVmSys::importPageTable(int pid, Memory * ram)
{
	// ����ҳ��
	reset();

	// ҳ�����ļ�
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	ifstream fin(fileName, ios::in | ios::binary);

	if (fin.is_open()){
		// ��ȡ����ҳ��
		for (int i = 0; i < e1; i++) {
			fin.read((char *)&root->entries[i], sizeof root->entries[i]);
		}
		// ��ȡ����ҳ��
		int index; // ����ҳ������λ��
		while (fin.read((char *)&index, sizeof index)) {
			// ���ػָ�����ҳ��
			table2[index] = new PageTable(e2);
			fin.read((char *)&table2[index]->used, sizeof table2[index]->used);
			// ��ȡ����ҳ���ҳ����
			for (int i = 0; i < e2; i++) fin.read((char *)&table2[index]->entries[i], sizeof table2[index]->entries[i]);

			// �ָ�����ҳ�����ر���
			root->entries[index].present = true;
			root->entries[index].number = index;
			root->used++;
			
		}
	}
	fin.close();

	// ����Ƿ���ҳ���Ѿ������������û�
	while (!ram->cache->isEmpty(pid)) {
		PageFrame tmp = ram->cache->pop(pid); // �Ѿ����û�����ҳ��

		unsigned pt1 = tmp.getVa().getNumber(SysConfig::OFFSET + SysConfig::PT2);
		unsigned pt2 = tmp.getVa().getNumber(SysConfig::OFFSET, SysConfig::PT2 + SysConfig::OFFSET);

		cout << "���½��� pid = " << dec << pid << "��ҳ�� : " << " ����ҳ��Ϊ " << tmp.getVa().value << " ����Ӧ��ҳ�����������滻 " << endl;

		// ��ҳ������Ч
		table2[pt1]->entries[pt2].present = false;
		table2[pt1]->used--;

		if (table2[pt1]->used == 0) { // ����ҳ��Ϊ��
			delete table2[pt1]; 
			root->entries[pt1].present = false;
		}
	}


}

void TwoLevelVmSys::savePageTable(int pid)
{
	// ������ļ�����
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// д���ļ�
	ofstream fout(fileName, ios::out | ios::binary );
	if (fout.is_open()) {
		// д�붥��ҳ��
		for (int i = 0; i < e1; i++) {
			fout.write((char *)&root->entries[i], sizeof root->entries[i]);// д�붥��ҳ���ȫ��ҳ����
		}

		// д�����ҳ��
		for (int i = 0; i < e1; i++) {
			if (root->entries[i].present) { // ����ҳ�����ڴ��У���Ҫд���ļ�
				fout.write((char *)&i, sizeof i); // д�����ҳ��ĵ�ַ��ʵ�����������±꣬���㵼���ļ�ʱ�ָ�ҳ��ṹ
				fout.write((char *)&table2[i]->used, sizeof table2[i]->used); // д�����ҳ���е���Чʹ�õ�ҳ��������
				for (int j = 0; j < e2; j++) {
					fout.write((char *)&table2[i]->entries[j], sizeof table2[i]->entries[j]); // д�����ҳ���ȫ��ҳ����
				}
			}
		}
	}

	fout.close();
}

void TwoLevelVmSys::recordPageTableTxt(int pid)
{
	// ������ļ�����
	char * fileName = new char[SysConfig::PT_FILE_LEN];
	strcpy_s(fileName, SysConfig::PT_FILE_LEN, SysConfig::PT_FILE);
	fileName[SysConfig::PT_FILE_I] = (char)(pid + 48);

	// д���ļ�
	ofstream fout(fileName, ios::out);
	if (fout.is_open()) {
		fout << "---------- ����ҳ���� ----------" << endl;
		// д�붥��ҳ��
		for (int i = 0; i < e1; i++) {
			if(root->entries[i].present) fout << "��" << i << "�� : ����ҳ��ĵ�ַ = " << root->entries[i].number << ", ��Чλ = " << root->entries[i].present << endl;
		}

		fout << "---------- ����ҳ���� ----------" << endl;

		// д�����ҳ��
		for (int i = 0; i < e1; i++) {
			if (root->entries[i].present) { // ����ҳ�����ڴ��У���Ҫд���ļ� 
				fout << "����ҳ���ַ = " << i << " : ----------" << endl;
				for (int j = 0; j < e2; j++) {
					if (table2[i]->entries[j].present) fout << "��" << j << "�� : ҳ��� = " << table2[i]->entries[j].number << ", ��Чλ = " << table2[i]->entries[j].present << endl;
				}
			}
		}
	}

	fout.close();
}

int TwoLevelVmSys::request(const Address & address, int pid, Memory * ram, RequestInfo & info)
{
	unsigned fNumber = 0;
	// �õ�PT1��PT2��ֵ
	unsigned pt1 = address.getNumber(SysConfig::OFFSET + SysConfig::PT2);
	unsigned pt2 = address.getNumber(SysConfig::OFFSET, SysConfig::PT2 + SysConfig::OFFSET);
	// �鿴����ҳ���ҵ���Ӧ��ҳ����
	if (!root->entries[pt1].present) { // ����ҳ����Ȼû�м���
		table2[pt1] = new PageTable(e2); // ���ض���ҳ���ڴ�

		// ���¶���ҳ����Ϣ
		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; 
		root->used++;
	}
	// ��ʱ����ҳ���Ѿ����ڴ棬�鿴����ҳ���Ӧ�ı���
	unsigned index = root->entries[pt1].number; // ȡ������ҳ�����ڵĵ�ַ/λ��
	// �鿴�Ƿ����ڴ���
	if (!table2[index]->entries[pt2].present) { // �����ڴ��У���Ҫ���ص��ڴ� 

		PageFrame frame(pid, address);
		fNumber = ram->allocate(frame); // �����µ�ҳ���ڴ���
		
		// ���¶���ҳ����Ϣ
		table2[index]->entries[pt2].present = true;
		table2[index]->entries[pt2].number = fNumber;
		table2[index]->used++;

		info.ptHit = false; // ȱʧ��Ϣ��¼
	}
	else { // ���ڴ���
		fNumber = table2[index]->entries[pt2].number; // ȡ��ҳ���
		ram->visit(fNumber); // ����LRU����

		info.ptHit = true;  // ������Ϣ��¼
	}
	return fNumber;
}

