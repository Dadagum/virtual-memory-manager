#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	页表
*/
class PageTable {
private:

public:
	Pte * entries;
	int size; // 页表项的数量
	int address; // 表示页表所在内存的地址，为了方便，形式为1，2，...，作为数组下标取得页表
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