#include "StandartSort.h"
#include <algorithm>

void StandartSort::operator()(DataStorage& data) const
{
	// access to std::sort out of my area
	// so sleep function is called when not swapped but check
	std::sort(data.begin(), data.end(), 
		[this](const int& a, const int& b) { sleep(DEFAULT_SLEEP / 2); return a < b; });
}
