#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	าณฑํ
*/
class PageTable {
private:

public:
	Pte * entries;
	int size;
	PageTable(int size) {
		this->size = size;
		entries = new Pte[size];
	}
	PageTable() {
		size = 0;
		entries = NULL;
	}
	~PageTable() {
		delete [] entries;
	}
};