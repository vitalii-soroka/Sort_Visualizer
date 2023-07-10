#pragma once
#include "SortAlgorithm.h"

struct QuickSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void quickSort(DataStorage& data, int low, int high) const;
	int partition(DataStorage& data, int low, int high) const;
};
