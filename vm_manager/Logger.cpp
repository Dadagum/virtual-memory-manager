#include "Logger.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void Logger::saveAddressList(Address * addresses, int total, int pid)
{
	// 文件名
	char * fileName = new char[SysConfig::VL_FILE_LEN]; // VL : visit list
	strcpy_s(fileName, SysConfig::VL_FILE_LEN, SysConfig::VISIT_LIST_FILE);
	fileName[SysConfig::VL_FILE_I] = (char)(pid + 48);

	ofstream fout(fileName, ios::out | ios::app);
	for (int i = 0; i < total; i++) fout << "第" << dec << i+1 << "次访问地址 : " << hex << addresses[i].value << endl;

	fout.close();
}

void Logger::saveRequestInfo(list<RequestInfo> & info, int total, int pid)
{
	// 文件名
	char * fileName = new char[SysConfig::VI_FILE_LEN]; // LI : visit info
	strcpy_s(fileName, SysConfig::VI_FILE_LEN, SysConfig::VISIT_INFO_FILE);
	fileName[SysConfig::VI_FILE_I] = (char)(pid + 48);

	int cnt = 1;
	ofstream fout(fileName, ios::out | ios::app);
	fout << "VP PF TLB PT" << endl; // 信息头部
	while (!info.empty()) {
		RequestInfo r = info.front();
		info.pop_front();
		fout << "第" << dec << cnt++ << "次访问 : " << hex << r.pNumber << " " << dec << r.fNumber << " " << r.tlbHit << " " << r.ptHit << endl;
	}
	fout.close();
}
