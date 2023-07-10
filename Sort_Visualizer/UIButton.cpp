#include "UIButton.h"
#include <assert.h>
#include <iostream>

#include "SFML/System/Mutex.hpp"
#include "SFML/System/Lock.hpp"

sf::Vector2f round(const sf::Vector2f vector)
{
	return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

UIButton::UIButton(sf::Vector2f position, sf::Vector2f size, const std::string& content) :
	UIRectangle(position, size)
{
	assert(font.loadFromFile("font/DS-DIGI.TTF"));
	
	this->content.setString(content);
	this->content.setCharacterSize(fontSize);
	this->content.setFont(font);		
	this->content.setFillColor(fontColor);
	calculateOrigin();
	this->content.setPosition(position + size / 2.0f);
}

void UIButton::setText(const std::string& text)
{
	content.setString(text);
	calculateOrigin();
}

void UIButton::calculateOrigin()
{
	textActive = false;

	sf::Vector2f center =
	{ 
	  this->content.getGlobalBounds().width, 
	  this->content.getGlobalBounds().height };

	auto localBounds = center / 2.0f + 
		sf::Vector2f{ this->content.getLocalBounds().left, 
					  this->content.getLocalBounds().top };

	auto rounded = round(localBounds);
	this->content.setOrigin(rounded);

	textActive = true;
}

void UIButton::draw(sf::RenderWindow& window)
{
	UIRectangle::draw(window);
	if (textActive)
	{
		window.draw(content);
	}
}
