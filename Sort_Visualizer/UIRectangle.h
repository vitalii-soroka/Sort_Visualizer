#pragma once
#include "UIElement.h"
#include "SFML/Graphics/RectangleShape.hpp"

/**
* UI rectangle shape 
*/
class UIRectangle : public UIElement
{
public:
	UIRectangle(sf::Vector2f position, sf::Vector2f size);

	sf::Vector2f getSize() const;

	void draw(sf::RenderWindow& window) override;

	void setFillColor(const sf::Color& color);

	bool checkInBounds(sf::Vector2f position) const;
	
	sf::Color getFillColor() const;

private:
	const sf::Color defaul_color = sf::Color(36, 36, 85);
	sf::RectangleShape rectangle;
};

inline sf::Color UIRectangle::getFillColor() const
{
	return rectangle.getFillColor();
}

inline bool UIRectangle::checkInBounds(sf::Vector2f position) const
{
	return rectangle.getGlobalBounds().contains(position);
}

inline sf::Vector2f UIRectangle::getSize() const 
{ 
	return rectangle.getSize(); 
}

inline void UIRectangle::setFillColor(const sf::Color& color) 
{ 
	rectangle.setFillColor(color); 
}
