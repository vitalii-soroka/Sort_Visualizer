#pragma once
#include "InputHandler.h"
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "SortAlgorithm.h"

using command_ptr = std::shared_ptr<Command>;
using algorithm_vector_ptr = std::vector<std::unique_ptr<SortAlgorithm>>;

class Application
{
public:
	Application();
	void run();

private:
	// function to draw in other thread
	void draw() const;

	algorithm_vector_ptr algorithms;
	std::vector<std::string> names;
	size_t currentIndx = 0;
	size_t algorithmsSize = 0;
	
	sf::RenderWindow window;
	Screen screen;

	command_ptr sort_command;
	command_ptr generate_command;
	command_ptr select_command;

	InputHandler input;
	DataStorage data;
};
