#include "UIRectangle.h"

UIRectangle::UIRectangle(sf::Vector2f position, sf::Vector2f size)
	: UIElement(position),
	rectangle(size)
{
	rectangle.setPosition(position);
	rectangle.setFillColor(sf::Color(36, 36, 85)); // temp
}

void UIRectangle::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}
