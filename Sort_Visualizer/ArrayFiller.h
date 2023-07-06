#pragma once
#include <vector>

class ArrayFiller
{
public:
	void operator()(std::vector<int>& array, int size, int min, int max);
};