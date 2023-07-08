#pragma once
#include "UIRectangle.h"
#include "SFML/Graphics/Text.hpp"

class UIButton : public UIRectangle
{
public:
	UIButton(sf::Vector2f position, sf::Vector2f size, const std::string& content);
	void draw(sf::RenderWindow& window) override;

	void setTextColor(const sf::Color& color);

	void setText(const std::string& text);

private:
	bool selected = false;

	sf::Font font; 
	sf::Text content;

	void calculateOrigin();
};

inline void UIButton::setTextColor(const sf::Color& color) { content.setFillColor(color); }


