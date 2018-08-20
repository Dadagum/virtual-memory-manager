#pragma once
#include"Address.h"

/*
	文件操作相关的工具类
*/
class FileUtil {
public:
	void saveAddressList(Address * list, int size); // 保存一个进程的虚拟地址访问序列
};