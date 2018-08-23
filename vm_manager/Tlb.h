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
	int capacity;
	int size;
public:
	Tlb(int capacity = SysConfig::TLB) {
		size = 0;
		this->capacity = capacity;
		entries = new LruList<TlbEntry>(capacity);
	}
	~Tlb() {
		delete entries;
	}
	void clear(); // ����TLB������
	int getfNumber(int pNumber); // ������ҳ���ҵ�ҳ��ţ�����TLB_MISS����ʾTLBû�м�¼�����м�¼ʱ����ҳ��ţ�ͬʱ����TLB�ķ��ʼ�¼
	void allocate(int pNumber, int fNumber);
};