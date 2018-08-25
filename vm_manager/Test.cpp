#include "Test.h"
#include"LruList.h"
#include"CachePool.h"
#include"RandomUtil.h"
#include<iomanip>
#include<iostream>
using namespace std;

void Test::testLruList()
{
	int capacity = 5;
	// 测试为空时
	LruList<int> l(5);
	l.print();

	// 插入数据1-5
	bool valid = false;
	int result;
	for (int i = 10; i < 15; i++) l.allocate(i, valid, result);
	l.print();

	// 测试访问数据
	int index = l.hasElement(10);
	if (index != -1) {
		l.visitByIndex(index);
		l.print();
	}

	// 测试再增加数据
	index = l.allocate(20, valid, result);
	cout << "index = " << index << endl; 
	if (valid) cout << "old = " << result << endl;
	l.print();
	cout << "now : " << l.get(index) << endl;
}

void Test::testNextAddressValue()
{
	RandomUtil random;
	/*	
	for (int i = 0; i < 10; i++) cout << hex << random.nextAddressValue(1) << endl;
	*/
	int total = 0;
	Address * test = random.nextAddressList(2, total, 256);
	for (int i = 0; i < total; i++) cout << hex << test[i].value << endl;
}

void Test::testCachePool()
{
	CachePool<int> pool(5);
	for (int i = 0; i < 5; i++) pool.put(2, i);
	while (!pool.isEmpty(2)) cout << pool.pop(2) << endl;
	for (int i = 6; i < 11; i++) pool.put(1, i);
	while (!pool.isEmpty(1)) cout << pool.pop(1) << endl;

}

