#pragma once
#include "SortAlgorithm.h"

struct RadixSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void countSort(DataStorage& data, int n, int div) const;
};
