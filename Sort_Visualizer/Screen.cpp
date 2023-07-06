#include "Screen.h"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
	: window(window)
{

}

void Screen::attachUI(std::unique_ptr<UIElement> element)
{
	elements.push_back(std::move(element));
}

void Screen::draw() const
{
	window.clear();

	for (const auto& elem : elements)
	{
		elem->draw(window);
	}

	window.display();
}
