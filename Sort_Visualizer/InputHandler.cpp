#include "InputHandler.h"

void InputHandler::handleInput(const sf::Event& event, sf::RenderWindow& window)
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

void InputHandler::handleMouseClick(const sf::Event& event, sf::RenderWindow& window)
{
	auto mousePos = sf::Mouse::getPosition(window);

	if (event.mouseButton.button == sf::Mouse::Left)
	{
		for (const auto& elem : buttons_map)
		{
			if (elem.first->checkInBounds({ (float)mousePos.x, (float)mousePos.y }))
			{
				auto prevColor = elem.first->getFillColor();

				elem.first->setFillColor(sf::Color::Red);

				elem.second->execute();

				elem.first->setFillColor(prevColor);

				break;
			}
		}
	}
}
