#include "UIDisplayer.h"
#include <SFML/System.hpp>
#include <algorithm>
#include <assert.h>
#include <iostream>

UIDataDisplayer::UIDataDisplayer(sf::Vector2f position, sf::Vector2f size, DataStorage* data)
	: UIRectangle(position, size), data(data)
{
	updateMax();
}

void UIDataDisplayer::updateMax()
{
	assert(data);

	auto it = std::max_element(data->begin(), data->end());
	if (it != data->end()) max_data = *it;
}

void UIDataDisplayer::draw(sf::RenderWindow& window)
{
	// draws box for data
	template_rect.setPosition(getPosition());
	template_rect.setSize(getSize());

	template_rect.setOutlineColor(outlineColor);
	template_rect.setOutlineThickness(outlineThick);
	template_rect.setFillColor(fillColor); 

	window.draw(template_rect);

	if (!data) return;

	// draws for each element corresponding rectangle
	template_rect.setFillColor(dataFillColor);
	template_rect.setOutlineThickness(dataOutlineThick);			 

	// calculates size of each element on board
	auto cellSizeX = getSize().x / (float)data->size(); 
	auto cellSizeY = getSize().y / (float)max_data;

	for (auto i = 0; i < data->size(); ++i)
	{
		template_rect.setSize({ cellSizeX, cellSizeY * (float)(*data)[i] });
		template_rect.setPosition(
			{ 
				getPosition().x + cellSizeX * (float)i,
				getPosition().y + getSize().y - template_rect.getSize().y 
			});
		window.draw(template_rect);
	}
}
