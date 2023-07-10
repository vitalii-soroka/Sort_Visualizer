#pragma once
#include "Commands.h"
#include "SFML/Window/Event.hpp"
#include "UIButton.h"
#include <map>

using button_ptr = std::shared_ptr<UIButton>;
using command_ptr = std::shared_ptr<Command>;
using buttonCommand_map = std::map<button_ptr, command_ptr>;

class InputHandler
{
public:
	void attachButton(button_ptr button, command_ptr command);
	void handleInput(const sf::Event& event, sf::RenderWindow& window) const;

private:
	void handleMouseClick(const sf::Event& event, const sf::RenderWindow& window) const;
	buttonCommand_map buttons_map;
};

inline void InputHandler::attachButton(button_ptr button, command_ptr command)
{
	buttons_map[button] = command;
}
