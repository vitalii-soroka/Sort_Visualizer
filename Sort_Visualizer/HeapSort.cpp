#include "HeapSort.h"

void HeapSort::operator()(DataStorage& data) const
{
	int n = data.size();

	for (int i = n / 2 - 1; i >= 0; --i)
	{
		make_heap(data, n, i);
	}

	// extract elements from heap
	for (int i = n - 1; i > 0; --i)
	{
		// move root to end
		data.swap(0, i);
		sleep(DEFAULT_SLEEP);
	
		// max make_heap on the reduced heap
		make_heap(data, i, 0);
	}
}

void HeapSort::make_heap(DataStorage& data, int N, int i) const
{
	// root
	int max = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < N && data[left] > data[max])
	{
		max = left;
	}

	if (right < N && data[right] > data[max])
	{
		max = right;
	}

	// not root
	if (max != i)
	{
		data.swap(i, max);

		sleep(DEFAULT_SLEEP);

		// recursive sub tree
		make_heap(data, N, max);
	}

}
