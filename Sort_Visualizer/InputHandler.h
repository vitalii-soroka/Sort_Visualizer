#pragma once
#include "SFML/Window/Event.hpp"
#include "Commands.h"
#include "UIButton.h"
#include <list>
#include <map>

class InputHandler
{
public:
	void attachButton(UIButton* button, Command* command);
	void handleInput(const sf::Event& event, sf::RenderWindow& window);

private:
	void handleMouseClick(const sf::Event& event, sf::RenderWindow& window);
	std::map<UIButton*, Command*> buttons_map;
};

inline void InputHandler::attachButton(UIButton* button, Command* command)
{
	buttons_map[button] = command;
}