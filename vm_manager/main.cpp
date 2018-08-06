#include<iostream>
#include"SysConfig.h"
using namespace std;

void test() {
	cout << SysConfig::PROCESS << endl;;
}

int main() {
	test();
	system("pause");
	return 0;
}