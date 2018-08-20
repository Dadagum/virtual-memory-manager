#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	ҳ��
*/
class PageTable {
private:
	Pte * entries;
	int size;
	int address; // ҳ�������ڴ��ַ��Ϊ�˼򻯣��˵�ַ��0,1,...,n��ʾ
public:
	PageTable(int size, int add = 0) {
		this->size = size;
		entries = new Pte[size];
		address = add;
	}
	PageTable() {
		size = 0;
		entries = NULL;
		address = 0;
	}
	void setValue(int size) {
		delete entries;
		entries = new Pte[size];
	}
	~PageTable() {
		delete [] entries;
	}
};