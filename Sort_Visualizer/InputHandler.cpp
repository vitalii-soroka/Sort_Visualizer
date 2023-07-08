#include "InputHandler.h"

InputHandler::InputHandler()
{
}

void InputHandler::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed :
	{
		auto mousePos = sf::Mouse::getPosition(window);

		if (event.mouseButton.button == sf::Mouse::Left)
		{
			for (const auto& elem : buttons_map)
			{
				if (elem.first->checkInBounds({ (float)mousePos.x, (float)mousePos.y }))
				{
					elem.first->setFillColor(sf::Color::Red);

					elem.second->execute();
					
					elem.first->setFillColor(sf::Color(36, 36, 85));
					
					break;
				}
			}
		}
	}
	default:
		break;
	}
}
