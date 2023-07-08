#pragma once
#include <set>
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "SortAlgorithm.h"
#include "InputHandler.h"

using SortAlgorithmPtr = void (SortAlgorithm::*)(std::vector<int>&) const;

//using SortAlgorithm = std::pair<std::set<std::unique_ptr<SortAlgorithm>>, int>;

class Application
{
public:
	Application();

	void run();

	void drawThreadFunction(sf::RenderWindow& window);

private:
	
	std::vector<std::unique_ptr<SortAlgorithm>> algorithms;
	std::vector<std::string> names;

	size_t a_index = 0;
	size_t a_size = 0;
	
	SortCommand sort_command;
	GenerateCommand generate_command;
	NextCommand next_command;
	PrevCommand prev_command;

	std::unique_ptr<NNextCommand> nnext_command;
	InputHandler input;
	DataStorage data;

	sf::RenderWindow window;
	Screen screen;
};