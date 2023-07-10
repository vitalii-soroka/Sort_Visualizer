#include "BubbleSort.h"
#include "SFML/System.hpp"

void BubbleSort::operator()(DataStorage& data) const
{
	for (size_t i = 0; i < data.size() - 1; ++i)
	{
		bool swapped = false;

		for (size_t j = 0; j < data.size() - 1; ++j)
		{
			if (data[j] > data[j + 1])
			{
				data.swap(j, j + 1);
				swapped = true;

				sleep(10); // temp
			}
		}
		if (!swapped) return;
	}
}
