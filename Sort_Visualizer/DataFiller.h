#pragma once
#include <vector>
#include "DataStorage.h"

/**
* Fills array with random data
*/
class DataFiller
{
public:
	void operator()(DataStorage& data, int size, int min, int max) const;
};