#include"Address.h"
#include<cmath>

unsigned Address::getNumber(const int start, const int end) const
{
	return (value % (unsigned)pow(2, end)) / pow(2, start);
}

unsigned Address::getNumber(const int start) const
{
	return value / pow(2, start);
}

