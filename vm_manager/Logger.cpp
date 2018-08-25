#include "Logger.h"
#include<iostream>
#include<fstream>
using namespace std;

void Logger::saveAddressList(Address * addresses, int total, int pid)
{
	// 文件名
	char * fileName = new char[SysConfig::VL_FILE_LEN];
	strcpy_s(fileName, SysConfig::VL_FILE_LEN, SysConfig::VISIT_LIST_FILE);
	fileName[SysConfig::VL_FILE_I] = (char)(pid + 48);

	ofstream fout(fileName, ios::out | ios::binary | ios::app);
	for (int i = 0; i < total; i++) fout.write((char *)&addresses[i].value, sizeof addresses[i].value);
	fout.close();
}

void Logger::saveRequestInfo(list<RequestInfo> & info, int total, int pid)
{
	// 文件名
	char * fileName = new char[SysConfig::VI_FILE_LEN];
	strcpy_s(fileName, SysConfig::VI_FILE_LEN, SysConfig::VISIT_INFO_FILE);
	fileName[SysConfig::VI_FILE_I] = (char)(pid + 48);

	ofstream fout(fileName, ios::out | ios::binary | ios::app);
	while (!info.empty()) {
		RequestInfo r = info.front();
		info.pop_front();
		fout.write((char *)&r, sizeof r);
	}
	fout.close();
}
