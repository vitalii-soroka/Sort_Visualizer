#pragma once
#include "UIElement.h"
#include "SFML/Graphics/Text.hpp"

class UIText : public UIElement
{
public:
	UIText(sf::Vector2f position, sf::Vector2f size, const std::string& content);

	void draw(sf::RenderWindow& window) override;

private:
	bool selected = false;

	sf::Font font;
	sf::Text content;
};