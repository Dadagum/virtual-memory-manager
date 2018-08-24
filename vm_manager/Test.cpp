#include "Test.h"
#include"LruList.h"
#include"LruList.cpp"
#include"CachePool.h"
#include"CachePool.cpp"
#include"RandomUtil.h"
#include<iomanip>
#include<iostream>
using namespace std;

void Test::testLruList()
{
	int capacity = 5;
	// 测试为空时
	LruList<int> list(5);
	list.print();

	// 插入数据1-5
	bool valid = false;
	int result;
	for (int i = 10; i < 15; i++) list.allocate(i, valid, result);
	list.print();

	// 测试访问数据
	int index = list.hasElement(10);
	if (index != -1) {
		list.visitByIndex(index);
		list.print();
	}

	// 测试再增加数据
	index = list.allocate(20, valid, result);
	cout << "index = " << index << endl; 
	if (valid) cout << "old = " << result << endl;
	list.print();
	cout << "now : " << list[index] << endl;
}

void Test::testNextAddressValue()
{
	RandomUtil random;
	/*	
	for (int i = 0; i < 10; i++) cout << hex << random.nextAddressValue(1) << endl;
	*/
	int total = 0;
	Address * test = random.nextAddressList(2, total, 256);
	for (int i = 0; i < total; i++) cout << hex << test[i].getValue() << endl;
}

void Test::testCachePool()
{
	CachePool<int> pool(5);
	for (int i = 0; i < 5; i++) pool.put(2, i);
	while (!pool.isEmpty(2)) cout << pool.pop(2) << endl;
	for (int i = 6; i < 11; i++) pool.put(1, i);
	while (!pool.isEmpty(1)) cout << pool.pop(1) << endl;

}

