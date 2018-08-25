#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	ҳ��
*/
class PageTable {
private:
public:
	Pte * entries;
	int size; // ҳ���������
	int used; // ��ʾҳ������Ч��ҳ��������
	PageTable(int size) {
		this->size = size;
		entries = new Pte[size];
		used = 0;
	}
	PageTable() {
		size = 0;
		entries = NULL;
	}
	~PageTable() {
		delete [] entries;
	}
};