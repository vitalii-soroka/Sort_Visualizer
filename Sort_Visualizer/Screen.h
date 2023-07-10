#pragma once
#include "UIDisplayer.h"
#include <list>
#include <memory>

class Screen 
{
public:
	explicit Screen(sf::RenderWindow& window);
	
	void attachUI(std::shared_ptr<UIElement> element);

	void draw() const;

private:
	sf::RenderWindow& window;
	std::list<std::shared_ptr<UIElement>> elements;
};
