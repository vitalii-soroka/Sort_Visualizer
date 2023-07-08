#pragma once
#include "SortAlgorithm.h"

struct MergeSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void sort();
};