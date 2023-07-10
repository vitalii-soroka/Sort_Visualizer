#include "DataFiller.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

void DataFiller::operator()(DataStorage& data, int size, int min, int max) const
{
	data.clear();
	data.reserve(size);

	srand((int)time(nullptr));

	for (int i = 0; i < size; ++i)
	{
		data.push_back(min + ( rand() % max ) );
	}
}
