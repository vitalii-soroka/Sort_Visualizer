#include "QuickSort.h"

void QuickSort::operator()(DataStorage& data) const
{
	quickSort(data, 0, data.size() - 1);
}

void QuickSort::quickSort(DataStorage& data, int low, int high) const
{
	if (low < high)
	{
		int partition_index = partition(data, low, high);

		quickSort(data, low, partition_index - 1);
		quickSort(data, partition_index + 1, high);
	}
}

int QuickSort::partition(DataStorage& data, int low, int high) const
{
	// takes last element as pivot
	int pivot = data[high];

	// righ position for pivot is smaller element
	int i = (low - 1);

	for (auto j = low; j < high; ++j)
	{
		// current element smaller than pivot
		if (data[j] < pivot)
		{
			++i;
			data.swap(i, j);
			sleep(DEFAULT_SLEEP);
		}
	}
	data.swap(i + 1, high);
	sleep(DEFAULT_SLEEP);
	
	return (i + 1);
}
