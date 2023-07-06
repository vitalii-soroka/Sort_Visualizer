#pragma once
#include <vector>
#include "Observer.h"
#include "UIRectangle.h"



class UIDisplayer : public UIRectangle, public Observer
{
public:
	UIDisplayer(sf::Vector2f position, sf::Vector2f size);

	void update() override;

	void attach(std::vector<int>* data);

	void draw(sf::RenderWindow& window) override;

private:
	sf::RectangleShape template_rect;
	std::vector<int>* data;

	int max_data = 100; // temp
};
