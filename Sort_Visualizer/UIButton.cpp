#include "UIButton.h"
#include <assert.h>
#include <iostream>

sf::Vector2f round(const sf::Vector2f vector)
{
	return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

UIButton::UIButton(sf::Vector2f position, sf::Vector2f size, const std::string& content) :
	UIRectangle(position, size)
{
	assert(font.loadFromFile("font/DS-DIGI.TTF"));
	
	this->content.setString(content);
	this->content.setCharacterSize(30); // temp
	this->content.setFont(font);		// temp
	this->content.setFillColor(sf::Color::White);
	
	// Calculate origin for text to be centre of text
	/*sf::Vector2f center = { this->content.getGlobalBounds().width, this->content.getGlobalBounds().height };
	auto localBounds = center / 2.0f + sf::Vector2f{ this->content.getLocalBounds().left, this->content.getLocalBounds().top };
	auto rounded = round(localBounds);
	this->content.setOrigin(rounded);*/
	calculateOrigin();

	// set position to center of UIRectangle
	this->content.setPosition(position + size / 2.0f);
}

void UIButton::setText(const std::string& text)
{
	content.setString(text);
	calculateOrigin();
}

void UIButton::calculateOrigin()
{
	sf::Vector2f center =
	{ this->content.getGlobalBounds().width, 
	  this->content.getGlobalBounds().height };

	auto localBounds = center / 2.0f + 
		sf::Vector2f{ this->content.getLocalBounds().left, 
					  this->content.getLocalBounds().top };

	auto rounded = round(localBounds);
	this->content.setOrigin(rounded);
}

void UIButton::draw(sf::RenderWindow& window)
{
	UIRectangle::draw(window);
	window.draw(content);
	//...
}
