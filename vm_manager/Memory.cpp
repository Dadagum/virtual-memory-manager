#include "Memory.h"

int Memory::allocate(const PageFrame & frame)
{
	bool valid = false;
	PageFrame result;
	int fNumber = memory->allocate(frame, valid, result);
	if (valid) { // 旧的页框被替换，需要更新属于进程的页表，先保存在缓存中
		cache->put(result.getPid(), result);
		cout << "发生页框替换事件，旧的页框为 : " << " 属于进程的pid = " << dec << result.getPid() << ", 页框号 = " << fNumber << endl;
	}
	return fNumber;
}

void Memory::visit(int fNumber)
{
	memory->visitByIndex(fNumber);
}
