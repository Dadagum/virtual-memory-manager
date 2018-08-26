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
		for (int i = 0; i < e1; i++) fin.read((char *)&root->entries[i], sizeof root->entries[i]);
		
		// ��ȡ����ҳ��
		int index; // ����ҳ������λ��
		while (fin.read((char *)&index, sizeof index)) {

			// ���ػָ�����ҳ��
			table2[index] = new PageTable(e2);
			fin.read((char *)&table2[index]->used, table2[index]->used);

			// ��ȡ����ҳ���ҳ����
			for (int i = 0; i < e2; i++) fin.read((char *)&table2[index]->entries[i], sizeof table2[index]->entries[i]);

			// ����Ƿ���ҳ���Ѿ������������û�
			while (!ram->cache->isEmpty(pid)) {
				PageFrame tmp = ram->cache->pop(pid); // �Ѿ����û�����ҳ��

				// ��ҳ������Ч
				table2[index]->entries[tmp.getVa()].present = false;
				table2[index]->used--;
			}

			if (table2[index]->used == 0) delete table2[index]; // ����ҳ��Ϊ��
			else {
				// �ָ�����ҳ�����ر���
				root->entries[index].present = true;
				root->entries[index].number = index;
				root->used++;
			}
		}
	}

	fin.close();
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
		for (int i = 0; i < e1; i++) fout.write((char *)&root->entries[i], sizeof root->entries[i]);// д�붥��ҳ���ȫ��ҳ����
		// д�����ҳ��
		for (int i = 0; i < e1; i++) {
			if (root->entries[i].present) { // ����ҳ�����ڴ��У���Ҫд���ļ�
				fout.write((char *)&i, sizeof i); // д�����ҳ��ĵ�ַ��ʵ�����������±꣬���㵼���ļ�ʱ�ָ�ҳ��ṹ
				fout.write((char *)&table2[i]->used, sizeof table2[i]->used); // д�����ҳ���е���Чʹ�õ�ҳ��������
				for (int j = 0; j < e2; j++) fout.write((char *)&table2[i]->entries[j], sizeof table2[i]->entries[j]); // д�����ҳ���ȫ��ҳ����
			}
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
	cout << "pt1 = " << pt1 << ", pt2 = " << pt2 << endl;
	// �鿴����ҳ���ҵ���Ӧ��ҳ����
	if (!root->entries[pt1].present) { // ����ҳ����Ȼû�м���
		table2[pt1] = new PageTable(e2); // ���ض���ҳ���ڴ�

		// ���¶���ҳ����Ϣ
		root->entries[pt1].present = true;
		root->entries[pt1].number = pt1; 
		root->used++;
	}
	// ��ʱ����ҳ���Ѿ����ڴ棬�鿴����ҳ���Ӧ�ı���
	int index = root->entries[pt1].number; // ȡ������ҳ�����ڵĵ�ַ/λ��
	cout << "index = " << index << endl;
	// �鿴�Ƿ����ڴ���
	if (!table2[index]->entries[pt2].present) { // �����ڴ��У���Ҫ���ص��ڴ� // ERROR

		PageFrame frame(pid, pt2);
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

int TwoLevelVmSys::request(const Address & addres, int pid, Memory * ram)
{
	return 0;
}


