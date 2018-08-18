#pragma once
#include"Address.h"
#include"Pte.h"
#include<iostream>

/*
	าณฑํ
*/
class PageTable {
private:
	Pte * entries;
	int size;
public:
	PageTable(int size) {
		this->size = size;
		entries = new Pte[size];
	}
	PageTable() {
		size = 0;
		entries = NULL;
	}
	void setValue(int size) {
		delete entries;
		entries = new Pte[size];
	}
	~PageTable() {
		delete entries;
	}
};