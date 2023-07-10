#pragma once
#include "UIElement.h"
#include "SFML/Graphics/RectangleShape.hpp"

class UIRectangle : public UIElement
{
public:
	UIRectangle(sf::Vector2f position, sf::Vector2f size);

	sf::Vector2f getSize() const;

	void draw(sf::RenderWindow& window) override;

	void setFillColor(const sf::Color& color);

	bool checkInBounds(sf::Vector2f position) const;
	
	sf::Color  getFillColor() const;

private:
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