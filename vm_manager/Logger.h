#pragma once
#include"Address.h"
#include"RequestInfo.h"
#include<list>
using namespace std;

/*
	记录运行过程到文件中
*/
class Logger {
public:
	static void saveAddressList(Address * addresses, int total, int pid); // 记录生成的地址列表
	static void saveRequestInfo(list<RequestInfo> & info, int total, int pid); // 将虚拟地址的访问信息保存到文件中
};