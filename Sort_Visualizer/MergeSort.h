#pragma once
#include "SortAlgorithm.h"

struct MergeSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void mergeSort(DataStorage& data, size_t begin, size_t end) const;
	void merge(DataStorage& data, size_t const left, size_t const mid, size_t const right) const;
};