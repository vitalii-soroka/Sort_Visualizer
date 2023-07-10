#pragma once
#include "SortAlgorithm.h"

struct HeapSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
private:
	void make_heap(DataStorage& data, int N, int i) const;
};
