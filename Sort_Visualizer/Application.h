#pragma once
#include <set>
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "SortAlgorithm.h"
#include "InputHandler.h"

using SortAlgorithmPtr = void (SortAlgorithm::*)(std::vector<int>&) const;

class Application
{
public:
	Application();
	void run();

private:
	void drawThreadFunction() const;
	
	std::vector<std::unique_ptr<SortAlgorithm>> algorithms;
	std::vector<std::string> names;

	size_t a_index = 0;
	size_t a_size = 0;
	
	sf::RenderWindow window;
	Screen screen;
	SortCommand sort_command;
	GenerateCommand generate_command;
	std::unique_ptr<NNextCommand> select_command;

	InputHandler input;
	DataStorage data;
};