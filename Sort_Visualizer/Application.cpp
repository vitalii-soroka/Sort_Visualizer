#include "Application.h"
#include "Commands.h"
#include "DataFiller.h"
#include "SFML/System.hpp"
#include "UIButton.h";
#include "UIDisplayer.h";
#include <functional>

#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "StandartSort.h"

using std::make_unique;
using std::make_shared;
using std::move;
using sf::Event;
using sf::Thread;
using sf::Vector2f;

// hardcoded application details
Application::Application() :
	window(sf::VideoMode(800, 600), "Sort Machine", sf::Style::Close),
	screen(window)
{
	window.setFramerateLimit(60);

	// Algorithms names
	names.emplace_back("Bubble");
	names.emplace_back("Selection");
	names.emplace_back("Insertion");
	names.emplace_back("Merge");
	names.emplace_back("Quick");
	names.emplace_back("Heap");
	names.emplace_back("Radix");
	names.emplace_back("std::sort");

	// Algorithms implementations
	algorithms.emplace_back(new BubbleSort);
	algorithms.emplace_back(new SelectionSort);
	algorithms.emplace_back(new InsertionSort);
	algorithms.emplace_back(new MergeSort);
	algorithms.emplace_back(new QuickSort);
	algorithms.emplace_back(new HeapSort);
	algorithms.emplace_back(new RadixSort);
	algorithms.emplace_back(new StandartSort);

	algorithmsSize = algorithms.size();

	// UI Elements
	auto sortButton = make_shared<UIButton>(Vector2f(300, 500), Vector2f(200, 50), "Sort");
	auto generateButton = make_shared<UIButton>(Vector2f(550, 500),Vector2f(200, 50), "Generate");
	auto selectButton = make_shared<UIButton>(Vector2f(50, 500), Vector2f(200, 50), names[0]);
	auto displayer = make_shared<UIDataDisplayer>(Vector2f(50, 50), Vector2f(700, 400), &data);

	// Commands - select next command
	select_command = make_shared<NextCommand>(algorithms, names, currentIndx, selectButton);
	sort_command = make_shared<SortCommand>(data, algorithms, currentIndx);
	generate_command = make_shared<GenerateCommand>(data, *displayer);

	// Input - attaches button to command
	input.attachButton(sortButton, sort_command);
	input.attachButton(generateButton, generate_command);
	input.attachButton(selectButton, select_command);

	// generate array
	generate_command->execute();

	// Screen UI - attaches buttons
	screen.attachUI(generateButton);
	screen.attachUI(sortButton);
	screen.attachUI(selectButton);
	screen.attachUI(displayer);
}

void Application::draw() const
{
	while (window.isOpen())
	{
		screen.draw();
	}
}

void Application::run()
{
	// Create the draw thread
	Thread drawThread([this]() { draw(); });
	// should disable window before using in other threads
	window.setActive(false);	
	drawThread.launch();

	// create the window and handle its events in the main thread!
	Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			input.handleInput(event, window);
		}
	}
	drawThread.wait();
}