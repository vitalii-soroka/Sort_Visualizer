#include "StandartSort.h"
#include <algorithm>

void StandartSort::operator()(DataStorage& data) const
{
	//
	std::sort(data.begin(), data.end(), 
		[this](const int& a, const int& b) { sleep(10); return a < b; });
}
