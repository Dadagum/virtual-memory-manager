#pragma once
#include"TlbEntry.h"

/*
	TLB���ݽṹ
*/
class Tlb {
private:
	TlbEntry * entries;
public:
	Tlb() {
		entries = new TlbEntry[SysConfig::TLB];
	}
	~Tlb() {
		delete[] entries;
	}
	// ����TLB������
	void clear() {
		for (int i = 0; i < SysConfig::TLB; i++) entries[i].clear();
	}
	// ������ҳ���ҵ�ҳ��ţ�����TLB_MISS��TLBû�м�¼
	int getfNumber(int pNumber);
	// ����TLB����
	void update(int pNumber);
};