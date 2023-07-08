#pragma once
#include "SFML/Window/Event.hpp"
#include "Commands.h"
#include "UIButton.h"
#include <list>
#include <map>

class InputHandler
{
public:
	InputHandler();

	void attachButton(UIButton* button, Command* command) { buttons_map[button] = command; }
	void handleInput(const sf::Event& event, sf::RenderWindow& window);

private:
	std::unique_ptr<sf::Thread> inputThread;

	std::map<UIButton*, Command*> buttons_map;
};