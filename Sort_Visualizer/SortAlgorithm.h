#pragma once
#include <vector>
#include "DataStorage.h"
#include "SFML/System/Sleep.hpp"

constexpr sf::Int32 DEFAULT_SLEEP = 20;

/**
* Interface for all algorithms 
*/
struct SortAlgorithm 
{
	virtual ~SortAlgorithm() = default;
	virtual void operator()(DataStorage& array) const = 0;

protected:
	void sleep(sf::Int32 milliseconds = DEFAULT_SLEEP) const;
};
