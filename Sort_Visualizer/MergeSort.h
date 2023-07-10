#pragma once
#include "SortAlgorithm.h"

struct MergeSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void mergeSort(DataStorage& data, int begin, int end) const;
	void merge(DataStorage& data, int const left, int const mid, int const right) const;
};
