#include "UIDisplayer.h"
#include <algorithm>
#include <iostream>
#include <SFML/System.hpp>

UIDisplayer::UIDisplayer(sf::Vector2f position, sf::Vector2f size)
	: UIRectangle(position, size)
{
	
}

UIDisplayer::UIDisplayer(sf::Vector2f position, sf::Vector2f size, DataStorage* data)
	: UIDisplayer(position, size)
	
{
	attach(data);
}

void UIDisplayer::attach(DataStorage* data)
{
	this->data = data; 

	auto it = std::max_element(data->begin(), data->end());

	if (it != data->end()) max_data = *it;
}

void UIDisplayer::draw(sf::RenderWindow& window)
{
	template_rect.setPosition(getPosition());
	template_rect.setSize(getSize());

	template_rect.setOutlineColor(sf::Color::White); // temp
	template_rect.setOutlineThickness(2);			 // temp
	template_rect.setFillColor(sf::Color::Black);   // temp

	window.draw(template_rect);

	if (!data) return;

	template_rect.setFillColor(sf::Color(36, 36, 85));
	template_rect.setOutlineThickness(0);			 // temp

	auto cellSizeX = getSize().x / data->size(); // temp
	auto cellSizeY = getSize().y / max_data;

	for (auto i = 0; i < data->size(); ++i)
	{
		template_rect.setSize({ cellSizeX, cellSizeY * (float)(*data)[i] });
		template_rect.setPosition({ getPosition().x + cellSizeX * i,
			getPosition().y + getSize().y - template_rect.getSize().y });

		window.draw(template_rect);
	}

	
}
