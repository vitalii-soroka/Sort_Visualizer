#include "UIRectangle.h"

UIRectangle::UIRectangle(sf::Vector2f position, sf::Vector2f size)
	: UIElement(position),
	rectangle(size)
{
	rectangle.setPosition(position);
	rectangle.setFillColor(defaul_color);
}

void UIRectangle::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}
