#pragma once
#include "UIDisplayer.h"
#include <list>
#include <memory>

class Screen : public Observer
{
public:
	Screen(sf::RenderWindow& window);
	
	void attachUI(std::unique_ptr<UIElement> element);

	void draw() const;

	void update() override { draw(); }

private:
	sf::RenderWindow& window;
	std::list<std::unique_ptr<UIElement>> elements;
};

