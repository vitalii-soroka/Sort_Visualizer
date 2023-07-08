#include "Application.h"
#include <functional>
#include "UIButton.h";
#include "UIDisplayer.h";
#include "BubbleSort.h"
#include "DataFiller.h"
#include "SFML/System.hpp"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "Commands.h"

Application::Application() : 
	window(sf::VideoMode(800, 600), "Sort Machine", sf::Style::Close),
	screen(window),
	sort_command(data, algorithms, a_index),
	generate_command(data),
	next_command(a_size, a_index),
	prev_command(a_size, a_index)
{
	window.setFramerateLimit(60);

	// Algorithms 
	names.emplace_back("BubbleSort");
	names.emplace_back("SelectionSort");
	names.emplace_back("InsertionSort");

	algorithms.push_back(std::make_unique<BubbleSort>(BubbleSort()));
	algorithms.push_back(std::make_unique<SelectionSort>(SelectionSort()));
	algorithms.push_back(std::make_unique<InsertionSort>(InsertionSort()));
	
	//auto next = std::make_unique<UIButton>(sf::Vector2f(300, 500), sf::Vector2f(100, 50), "NEXT");
	//auto prev = std::make_unique<UIButton>(sf::Vector2f(100, 500), sf::Vector2f(100, 50), "PREV");

	auto sort = std::make_unique<UIButton>(sf::Vector2f(300, 500), sf::Vector2f(100, 50), "Sort");
	auto generate = std::make_unique<UIButton>(sf::Vector2f(450, 500), sf::Vector2f(200, 50), "Generate");
	auto text = std::make_unique<UIButton>(sf::Vector2f(50, 500), sf::Vector2f(200, 50), names[0]);

	nnext_command = std::make_unique<NNextCommand>(algorithms, names, a_index, text.get());
	

	// Input
	input.attachButton(sort.get(), &sort_command);
	input.attachButton(generate.get(), &generate_command);
	input.attachButton(text.get(), nnext_command.get());

	//input.attachButton(next.get(), &next_command);
	//input.attachButton(prev.get(), &prev_command);

	// Screen UI
	//screen.attachUI(std::move(prev));
	//screen.attachUI(std::move(next));
	screen.attachUI(std::move(generate));
	screen.attachUI(std::move(sort));
	screen.attachUI(std::move(text));
	screen.attachUI(std::make_unique<UIDisplayer>(sf::Vector2f(50, 50), sf::Vector2f(700, 400), &data));

	

	a_size = algorithms.size();
}

void Application::drawThreadFunction(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		screen.draw();
	}
}

void Application::run() 
{
	DataFiller filler;
	filler(data, 100, 1, 100);

	// Create the draw thread
	window.setActive(false);
	sf::Thread drawThread([this]() { drawThreadFunction(std::ref(window)); });
	drawThread.launch();

	// Main loop 'always create the window and handle its events in the main thread for maximum portability'.
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			// Input handling code here
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
			else
			{
				input.handleInput(event, window);
			}
		}
	}
	drawThread.wait();
}
