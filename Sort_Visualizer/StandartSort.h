#pragma once
#include "SortAlgorithm.h"

struct StandartSort : public SortAlgorithm
{
	void operator()(DataStorage& data) const override;
};