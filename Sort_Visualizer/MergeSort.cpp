#include "MergeSort.h"

void MergeSort::operator()(DataStorage& data) const
{
	mergeSort(data, 0, data.size() - 1);
}

void MergeSort::mergeSort(DataStorage& data, int begin, int end) const
{
	if (begin >= end) return;

	int mid = begin + (end - begin) / 2;
	
	mergeSort(data, begin, mid);
	mergeSort(data, mid + 1, end);
	merge(data, begin, mid, end);
}

void MergeSort::merge(DataStorage& data, int const left, int const mid, int const right) const
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	auto* leftArray = new int[subArrayOne];
	auto * rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
	{
		leftArray[i] = data[left + i];
	}
	for (auto j = 0; j < subArrayTwo; j++)
	{
		rightArray[j] = data[mid + 1 + j];
	}

	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;

	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
		{
			sleep(DEFAULT_SLEEP / 2);
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			indexOfSubArrayOne++;
		}
		else
		{
			sleep(DEFAULT_SLEEP / 2);
			data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) 
	{
			sleep(DEFAULT_SLEEP / 2);
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) 
	{
		sleep(DEFAULT_SLEEP / 2);
		data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}
