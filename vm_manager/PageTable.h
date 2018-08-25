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
	int used; // 表示页表中有效的页表项数量
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