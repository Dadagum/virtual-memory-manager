#include<iostream>
#include"SysConfig.h"
#include"VMRunner.h"
#include"Test.h"
using namespace std;

void test() {
	Test test;
	// test.testLruList();
	test.testNextAddressValue();
	//test.testCachePool();
}

void run() {
	VMRunner runner;
	runner.run();
}

int main() {
	test();
	//run();
	system("pause");
	return 0;
}