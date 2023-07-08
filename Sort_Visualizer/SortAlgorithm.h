#pragma once
#include <vector>
#include "DataStorage.h"
#include "SFML/System/Sleep.hpp"

struct SortAlgorithm 
{
	virtual ~SortAlgorithm() = default;
	virtual void operator()(DataStorage& array) const = 0;

protected:
	void sleep(sf::Int32 milliseconds) const;
};
