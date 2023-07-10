#include "InputHandler.h"

void InputHandler::handleInput(const sf::Event& event, sf::RenderWindow& window) const
{	
	// Click handling
	if (event.type == sf::Event::MouseButtonPressed)
	{
		handleMouseClick(event, window);
	}
	// Close handling
	else if (event.type == sf::Event::Closed ||
		(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
	{
		window.close();
	}
	
}

void InputHandler::handleMouseClick(const sf::Event& event, const sf::RenderWindow& window) const
{
	auto mousePos = sf::Mouse::getPosition(window);

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		// checks every button for mouse overlap
		for (const auto& pair : buttons_map)
		{
			if (pair.first->checkInBounds({ (float)mousePos.x, (float)mousePos.y }))
			{
				// button color is changed while proceed  
				auto prevColor = pair.first->getFillColor();

				pair.first->setFillColor(sf::Color::Red);
				pair.second->execute();
				pair.first->setFillColor(prevColor);

				break;
			}
		}
	}
}
