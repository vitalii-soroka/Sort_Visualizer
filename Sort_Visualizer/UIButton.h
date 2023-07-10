#pragma once
#include "UIRectangle.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Color.hpp"

/**
* Rectangle shape button
*/
class UIButton : public UIRectangle
{
public:
	UIButton(sf::Vector2f position, sf::Vector2f size, const std::string& content);
	void draw(sf::RenderWindow& window) override;

	void setTextColor(const sf::Color& color);
	void setText(const std::string& text);

private:
	const int fontSize = 30;
	const sf::Color fontColor = sf::Color::White;

	bool textActive = false;

	sf::Font font; 
	sf::Text content;

	// calculates origin of text to be on centre
	void calculateOrigin();

};

inline void UIButton::setTextColor(const sf::Color& color)
{ 
	content.setFillColor(color);
}


