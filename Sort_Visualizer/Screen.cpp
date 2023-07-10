#include "Screen.h"
#include <iostream>

Screen::Screen(sf::RenderWindow& window)
	: window(window)
{}

void Screen::attachUI(std::shared_ptr<UIElement> element)
{
	elements.push_back(std::move(element));
}

void Screen::draw() const
{
	window.clear();

	for (const auto& element : elements)
	{
		element->draw(window);
	}
	window.display();
}
