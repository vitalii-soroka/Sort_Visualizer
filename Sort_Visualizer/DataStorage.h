#pragma once
#include <vector>

/**
* Wrapper for data container,
* controls access
*/
class DataStorage
{
public:
	explicit DataStorage() = default;

	int& operator[](int index);
	int getAt(int index) const;

	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	size_t size() const;

	void swap(size_t a, size_t b);

	void clear();
	void reserve(size_t n);
	void push_back(int element);

private:
	std::vector<int> data;
};
