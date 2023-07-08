#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"



class UIElement
{
public:
	virtual ~UIElement() = default;
	explicit UIElement(sf::Vector2f position);

	sf::Vector2f getPosition() const;
	
	virtual void draw(sf::RenderWindow& window) = 0;

private:
	sf::Vector2f position;
};

inline sf::Vector2f UIElement::getPosition() const { return position; }