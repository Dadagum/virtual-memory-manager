#pragma once
#include"Address.h"
#include"RequestInfo.h"
#include<list>
using namespace std;

/*
	��¼���й��̵��ļ���
*/
class Logger {
public:
	static void saveAddressList(Address * addresses, int total, int pid); // ��¼���ɵĵ�ַ�б�
	static void saveRequestInfo(list<RequestInfo> & info, int total, int pid); // �������ַ�ķ�����Ϣ���浽�ļ���
};