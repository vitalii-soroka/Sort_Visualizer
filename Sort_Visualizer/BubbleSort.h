#pragma once
#include "SortAlgorithm.h"

struct BubbleSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
};
