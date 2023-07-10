#include "InsertionSort.h"

void InsertionSort::operator()(DataStorage& data) const
{
	int key;

	for (int i = 1; i < data.size(); ++i)
	{
		key = data[i];

		int j = i - 1;

		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = key;
		
		sleep(DEFAULT_SLEEP * 5);
	}
}
