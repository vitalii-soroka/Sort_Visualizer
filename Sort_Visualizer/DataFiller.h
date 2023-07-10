#pragma once
#include <vector>
#include "DataStorage.h"

class DataFiller
{
public:
	void operator()(DataStorage& data, int size, int min, int max);
};