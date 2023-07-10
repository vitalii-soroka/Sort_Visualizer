#include "Application.h"

#include <functional>

#include "SFML/System.hpp"

#include "UIButton.h";
#include "UIDisplayer.h";

#include "DataFiller.h"
#include "Commands.h"

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "StandartSort.h"
#include "MergeSort.h"

Application::Application() : 
	window(sf::VideoMode(800, 600), "Sort Machine", sf::Style::Close),
	screen(window),
	sort_command(data, algorithms, a_index),
	generate_command(data)
{
	window.setFramerateLimit(60);

	// Algorithms 
	names.emplace_back("Bubble");
	names.emplace_back("Selection");
	names.emplace_back("Insertion");
	names.emplace_back("Merge");
	names.emplace_back("Standart");

	algorithms.push_back(std::make_unique<BubbleSort>(BubbleSort()));
	algorithms.push_back(std::make_unique<SelectionSort>(SelectionSort()));
	algorithms.push_back(std::make_unique<InsertionSort>(InsertionSort()));
	algorithms.push_back(std::make_unique<MergeSort>(MergeSort()));
	algorithms.push_back(std::make_unique<StandartSort>(StandartSort()));
	
	// Buttons
	auto mergeSort = std::make_unique<UIButton>(sf::Vector2f(300, 500), sf::Vector2f(100, 50), "Sort");
	auto generate = std::make_unique<UIButton>(sf::Vector2f(450, 500), sf::Vector2f(200, 50), "Generate");
	auto text = std::make_unique<UIButton>(sf::Vector2f(50, 500), sf::Vector2f(200, 50), names[0]);

	// Commands
	select_command = std::make_unique<NNextCommand>(algorithms, names, a_index, text.get());
	
	// Input
	input.attachButton(mergeSort.get(), &sort_command);
	input.attachButton(generate.get(), &generate_command);
	input.attachButton(text.get(), select_command.get());

	// Screen UI
	screen.attachUI(std::move(generate));
	screen.attachUI(std::move(mergeSort));
	screen.attachUI(std::move(text));
	screen.attachUI(std::make_unique<UIDisplayer>(sf::Vector2f(50, 50), sf::Vector2f(700, 400), &data));

	a_size = algorithms.size();
}

void Application::drawThreadFunction() const
{
	while (window.isOpen())
	{
		screen.draw();
	}
}

void Application::run() 
{
	DataFiller data_filler;
	data_filler(data, 100, 1, 100);

	// Create the draw thread
	window.setActive(false);	// should disable window before using in other threads
	sf::Thread drawThread([this]() { drawThreadFunction(); });
	drawThread.launch();

	// Main loop 'always create the window and handle its events in the main thread for maximum portability'.
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			input.handleInput(event, window);
		}
	}
	drawThread.wait();
}
