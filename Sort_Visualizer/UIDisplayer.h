#pragma once
#include <vector>
#include "Observer.h"
#include "UIRectangle.h"
#include "DataStorage.h"

class UIDisplayer : public UIRectangle
{
public:
	UIDisplayer(sf::Vector2f position, sf::Vector2f size);
	UIDisplayer(sf::Vector2f position, sf::Vector2f size, DataStorage* data);

	void attach(DataStorage* data);

	void draw(sf::RenderWindow& window) override;

private:
	sf::RectangleShape template_rect;
	DataStorage* data;

	int max_data = 100; // temp
};
