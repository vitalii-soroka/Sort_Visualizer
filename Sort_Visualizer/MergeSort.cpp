#include "MergeSort.h"

void MergeSort::operator()(DataStorage& data) const
{
	mergeSort(data, 0, data.size() - 1);
}

void MergeSort::mergeSort(DataStorage& data, size_t begin, size_t end) const
{
	if (begin >= end) return;

	int mid = begin + (end - begin) / 2;
	
	mergeSort(data, begin, mid);
	mergeSort(data, mid + 1, end);
	merge(data, begin, mid, end);
}

void MergeSort::merge(DataStorage& data, size_t const left, size_t const mid, size_t const right) const
{
	size_t const subArrayOne = mid - left + 1;
	size_t const subArrayTwo = right - mid;

	auto* leftArray = new int[subArrayOne];
	auto * rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = data[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = data[mid + 1 + j];

	size_t indexOfSubArrayOne = 0;
	size_t indexOfSubArrayTwo = 0;

	size_t indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
		{
			sleep(10);
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];

			indexOfSubArrayOne++;
		}
		else
		{
			sleep(10);
			data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) 
	{
			sleep(10);
			data[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) 
	{
		sleep(10);
		data[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}

	delete[] leftArray;
	delete[] rightArray;
}
