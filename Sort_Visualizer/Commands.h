#pragma once
#include <vector>
#include "SortAlgorithm.h"
#include "SFML/System/Thread.hpp"
#include "DataFiller.h"
#include "UIButton.h"

/**
* Default Commands
*/
struct Command {
	virtual ~Command() = default;
	virtual void execute() = 0;
};

class NoCommand : public Command
{
	void execute() override {/*  */};
};

class DataCommand
{
public:
	virtual ~DataCommand() = default;
	virtual void execute(SortAlgorithm* algorithm, std::vector<int>& data) = 0;
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
	explicit GenerateCommand(DataStorage& data) :
		data(data)
	{ }

	void execute() override
	{
		filler(data, 100, 1, 100); // temp
	}

private:
	
	DataStorage& data;
	DataFiller filler;
};

class NextCommand : public Command
{
public:
	explicit NextCommand(size_t& size, size_t& current) :
		size(size), current(current) { }

	void execute() override
	{
		if (current >= size - 1) current = 0;
		else ++current;
	}

private:
	size_t& size;
	size_t& current;
};

class PrevCommand : public Command
{
public:
	explicit PrevCommand(size_t& size, size_t& current) :
		size(size), current(current)
	{ }

	void execute() override
	{
		if (current == 0) current = size - 1;
		else --current;
	}

private:
	size_t& size;
	size_t& current;
};


class NNextCommand : public Command
{
public:
	explicit NNextCommand(
		std::vector<std::unique_ptr<SortAlgorithm>>& algorithms,
		std::vector<std::string>& names, size_t& current, UIButton* ref) :

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
	size_t& current;
	UIButton* button;
	std::vector<std::unique_ptr<SortAlgorithm>>& algorithms;
	std::vector<std::string>& names;
};

class UpdateCommand : public Command
{
public:
	explicit UpdateCommand(UIButton& ref, std::vector<std::string>& names, size_t& size) :
		button(ref), names(names), index(size) { }

	void execute() override
	{
		button.setText(names[index]);
	}

private:
	UIButton& button;
	std::vector<std::string>& names;
	size_t& index;
};