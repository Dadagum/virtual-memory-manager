#include"Tlb.h"

void Tlb::clear(int capacity = SysConfig::TLB)
{
	entries->reset(capacity);
}

int Tlb::getfNumber(int pNumber)
{
	for (int i = 0; i < entries->getSize(); i++)
		if (entries->get(i).getpNumber == pNumber) { // TLBÖĞÓĞ¼ÇÂ¼
			return entries->get(i).getfNumber();
		}
	return Constant::TLB_MISS; // TLBÈ±Ê§
}

void Tlb::allocate(const TlbEntry & entry)
{
	bool valid = false;
	TlbEntry result;
	entries->allocate(entry, valid, result);
}
