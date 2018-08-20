#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	页表
*/
class PageTable {
private:
	Pte * entries;
	int size;
	int address; // 页表所在内存地址，为了简化，此地址用0,1,...,n表示
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