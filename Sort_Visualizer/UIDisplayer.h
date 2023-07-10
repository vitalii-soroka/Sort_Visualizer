#pragma once
#include <vector>
#include "UIRectangle.h"
#include "DataStorage.h"

class UIDataDisplayer : public UIRectangle
{
public:
	UIDataDisplayer(sf::Vector2f position, sf::Vector2f size, DataStorage* data);

	void draw(sf::RenderWindow& window) override;
	void updateMax();
private:
	sf::RectangleShape template_rect;
	DataStorage* data;
	int max_data;

	// board const
	const float outlineThick = 2.f;
	const sf::Color outlineColor = sf::Color::White;
	const sf::Color fillColor = sf::Color::Black;
	// data const
	const float dataOutlineThick = 0.f;
	const sf::Color dataFillColor = sf::Color(36, 36, 85);
};
