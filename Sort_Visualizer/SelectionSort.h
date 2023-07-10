#pragma once
#include <vector>
#include "SortAlgorithm.h"

struct SelectionSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override ;
};
