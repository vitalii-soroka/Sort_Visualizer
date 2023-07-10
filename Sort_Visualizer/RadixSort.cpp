#include "RadixSort.h"

void RadixSort::operator()(DataStorage& data) const
{
	int max = INT_MIN;

	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	
	for (int div = 1; max / div > 0; div *= 10)
	{
		countSort(data, data.size(), div);
	}

}

void RadixSort::countSort(DataStorage& data, int n, int div) const
{
	int count[10];
	for (int i = 0; i < 10; ++i)
	{
		count[i] = 0;
	}

	// Increasing count
	for (int i = 0; i < n; ++i)
	{
		count[(data[i] / div) % 10]++;
	}

	for (int i = 1; i < 10; ++i) 
	{
		count[i] += count[i - 1];
	}

	int* temp = new int[n];

	// Building the temporary array.
	for (int i = n - 1; i > -1; --i) 
	{
		temp[count[(data[i] / div) % 10] - 1] = data[i];
		count[(data[i] / div) % 10]--;
	}

	// Updating the elements in array.
	for (int i = 0; i < n; ++i)
	{
		data[i] = temp[i];
		sleep(DEFAULT_SLEEP);
	}

	delete temp;
}
