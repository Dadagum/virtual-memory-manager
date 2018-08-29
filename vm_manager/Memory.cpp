#include "Memory.h"

int Memory::allocate(const PageFrame & frame)
{
	bool valid = false;
	PageFrame result;
	int fNumber = memory->allocate(frame, valid, result);
	if (valid) { // �ɵ�ҳ���滻����Ҫ�������ڽ��̵�ҳ���ȱ����ڻ�����
		cache->put(result.getPid(), result);
		cout << "����ҳ���滻�¼����ɵ�ҳ��Ϊ : " << " ���ڽ��̵�pid = " << dec << result.getPid() << ", ҳ��� = " << fNumber << endl;
	}
	return fNumber;
}

void Memory::visit(int fNumber)
{
	memory->visitByIndex(fNumber);
}
