#include "BubbleSort.h"

void BubbleSort::sort(std::vector<int>& array)
{
	for (std::vector<int>::size_type i = 0; i < array.size() - 1; ++i)
	{
		bool swapped = false;

		for (std::vector<int>::size_type j = 0; j < array.size() - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				swapped = true;
				
				notify(); // notify that changed
			}
		}
		if (!swapped) return;
	}
}
