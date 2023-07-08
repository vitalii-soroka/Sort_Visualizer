#include "SelectionSort.h"


void SelectionSort::operator()(DataStorage& data) const
{
	size_t min;

	for (size_t i = 0; i < data.size() - 1; ++i)
	{
		min = i;

		for (size_t j = i + 1; j < data.size(); ++j)
		{
			if (data[j] < data[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			data.swap(min, i);
			
			sleep(40);
		}
	}
}
