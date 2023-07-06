#pragma once
#include "SortAlgorithm.h"

class BubbleSort : public SortAlgorithm
{
public:
	BubbleSort() = default;

	void sort(std::vector<int>& array) override;

private:
};