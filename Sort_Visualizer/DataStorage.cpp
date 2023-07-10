#include "DataStorage.h"
#include "SFML/System/Mutex.hpp"
#include "SFML/System/Lock.hpp"

sf::Mutex mutex; // blocks concurent access

int& DataStorage::operator[](int index)
{
	sf::Lock lock(mutex);
	return data[index];
}

int DataStorage::getAt(int index) const
{
	sf::Lock lock(mutex);
	return data[index];
}

void DataStorage::clear()
{
	sf::Lock lock(mutex);
	data.clear();
}

void DataStorage::reserve(size_t n)
{
	sf::Lock lock(mutex);
	data.reserve(n);
}

void DataStorage::push_back(int value)
{
	sf::Lock lock(mutex);
	data.push_back(value);
}

std::vector<int>::iterator DataStorage::begin()
{
	sf::Lock lock(mutex);
	return data.begin();
}

std::vector<int>::iterator DataStorage::end()
{
	sf::Lock lock(mutex);
	return data.end();
}

size_t DataStorage::size() const
{
	sf::Lock lock(mutex);
	return data.size();
}

void DataStorage::swap(size_t a, size_t b)
{
	sf::Lock lock(mutex);
	std::swap(data[a], data[b]);
}
