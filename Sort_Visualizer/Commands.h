#pragma once
#include "DataFiller.h"
#include "SFML/System/Thread.hpp"
#include "SortAlgorithm.h"
#include "UIButton.h"
#include "UIDisplayer.h"
#include <assert.h>
#include <vector>

/**
* Commands to attach with buttons
*/
struct Command {
	virtual ~Command() = default;
	virtual void execute() = 0;
};

class NoCommand : public Command
{
	void execute() override {/*  */};
};

class SortCommand : public Command
{
public:
	SortCommand(DataStorage& data, 
		std::vector<std::unique_ptr<SortAlgorithm>>& algorithms, size_t& current) :
		data(data), algorithms(algorithms), current(current)
	{ }

	void execute() override
	{
		if (!algorithms[current].get() ) return;
		(*algorithms[current])(data);
	}
private:
	DataStorage& data;
	std::vector<std::unique_ptr<SortAlgorithm>>& algorithms;
	size_t& current;
};

class GenerateCommand : public Command
{
public:
	explicit GenerateCommand(DataStorage& data, UIDataDisplayer& displayer) :
		data(data), displayer(displayer)
	{ }

	void setParam(int newSize, int newMin, int newMax)
	{
		assert(min < max && size > 0);
		size = newSize;
		min = newMin;
		max = newMax;
	}

	void execute() override
	{
		filler(data, size, min, max);
		displayer.updateMax();
	}

private:
	int size = 100;
	int min = 1;
	int max = 100;

	DataStorage& data;
	UIDataDisplayer& displayer;
	DataFiller filler;
};

class NextCommand : public Command
{
public:
	explicit NextCommand(
		std::vector<std::unique_ptr<SortAlgorithm>>& algorithms,
		std::vector<std::string>& names, size_t& current, std::shared_ptr<UIButton> ref) :

		algorithms(algorithms),
		names(names),
		current(current),
		button(ref)
	{ }

	void execute() override
	{
		if (current >= algorithms.size() - 1) current = 0;
		else ++current;

		button->setText(names[current]);
	}

private:
	std::vector<std::unique_ptr<SortAlgorithm>>& algorithms;
	std::vector<std::string>& names;
	size_t& current;
	std::shared_ptr<UIButton> button;
};
