#include "ArrayFiller.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

void ArrayFiller::operator()(std::vector<int>& array, int size, int min, int max)
{
	array.clear();
	array.reserve(size);

	srand((int)time(nullptr));

	for (int i = 0; i < size; ++i)
	{
		array.push_back(min + ( rand() % max ) );
	}
}
