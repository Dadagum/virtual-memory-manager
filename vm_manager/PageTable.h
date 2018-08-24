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
	int address; // ��ʾҳ�������ڴ�ĵ�ַ��Ϊ�˷��㣬��ʽΪ1��2��...����Ϊ�����±�ȡ��ҳ��
	PageTable(int size, int address = -1) {
		this->size = size;
		entries = new Pte[size];
		this->address = address;
	}
	PageTable() {
		size = 0;
		entries = NULL;
		address = -1;
	}
	~PageTable() {
		delete [] entries;
	}
};