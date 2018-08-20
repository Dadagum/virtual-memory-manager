#pragma once
#include"TlbEntry.h"
#include"LruList.h"
#define TLB_MISS -1 // TLBȱʧ
#define TLBE_EMPTY -2 // TLB����Ϊ��

/*
	TLB���ݽṹ
*/
class Tlb {
private:
	LruList<TlbEntry> * entries;
public:
	Tlb() {
		entries = new LruList<TlbEntry>(SysConfig::TLB);
	}
	~Tlb() {
		delete entries;
	}
	void clear(); // ����TLB������
	int getfNumber(int pNumber); // ������ҳ���ҵ�ҳ��ţ�����TLB_MISS����ʾTLBû�м�¼�����м�¼ʱ����ҳ��ţ�ͬʱ����TLB�ķ��ʼ�¼
	void allocate(int pNumber, int fNumber);
};