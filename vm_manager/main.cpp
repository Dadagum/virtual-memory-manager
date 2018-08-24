#include<iostream>
#include"SysConfig.h"
#include"Test.h"
using namespace std;

void test() {
	Test test;
	// test.testLruList();
	//test.testNextAddressValue();
	test.testCachePool();
}

int main() {
	test();
	system("pause");
	return 0;
}