#pragma once
#include "SortAlgorithm.h"

struct InsertionSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
};