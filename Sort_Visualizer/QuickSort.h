#pragma once
#include "SortAlgorithm.h"

struct QuickSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void quickSort(DataStorage& data, size_t low, size_t high) const;
};