#pragma once
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include <map>

class Application
{
public:
	Application();

	void run();

private:

	//std::map<std::string, UIElement*, std::less<>> elements;
	sf::Event event;
	std::vector<int> data;
	sf::RenderWindow window;
	Screen screen;
};