#pragma once
#include"TlbEntry.h"
#include"LruList.h"
#include"SysConfig.h"

/*
	TLB���ݽṹ
*/
class Tlb {
private:
	LruList<TlbEntry> * entries;
public:
	Tlb(int capacity = SysConfig::TLB) {
		entries = new LruList<TlbEntry>(capacity);
	}
	~Tlb() {
		delete entries;
	}
	void clear(int capacity = SysConfig::TLB); // ����TLB������
	int getfNumber(int pNumber); // ������ҳ���ҵ�ҳ��ţ�����TLB_MISS����ʾTLBû�м�¼�����м�¼ʱ����ҳ��ţ�ͬʱ����TLB�ķ��ʼ�¼
	void allocate(const TlbEntry & entry);
};