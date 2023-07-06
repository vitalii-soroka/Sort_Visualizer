#include "Application.h"
#include "UIButton.h";
#include "UIDisplayer.h";
#include "BubbleSort.h"
#include "ArrayFiller.h"


Application::Application()
	: window(sf::VideoMode(800, 600), "Sort Machine", sf::Style::Close),
	screen(window)

{
	//window.setView(sf::View(sf::FloatRect(0, 0, 800, 600)));
	window.setFramerateLimit(60);

	// UI
	auto bTemp = std::make_unique<UIButton>(sf::Vector2f(500,50), sf::Vector2f(100,50), "Temp");
	auto bGenerate = std::make_unique<UIButton>(sf::Vector2f(500,250), sf::Vector2f(100,50), "Sort");
	auto bSort = std::make_unique<UIButton>(sf::Vector2f(500,150), sf::Vector2f(100,50), "Generate");
	auto displayer = std::make_unique<UIDisplayer>(sf::Vector2f(50, 50), sf::Vector2f(400, 400));

	displayer->attach(&data);
	
	screen.attachUI(std::move(bTemp));
	screen.attachUI(std::move(bGenerate));
	screen.attachUI(std::move(bSort));
	screen.attachUI(std::move(displayer));

}

void Application::run() 
{
	ArrayFiller filler; 
	filler(data, 100, 1, 100);

	BubbleSort bubble;
	bubble.attach(&screen);
	//bubble.sort(data);

	bool flag = true; // temp

	// Main loop
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			
		}

		screen.draw();
		if (flag)
		{
			bubble.sort(data);
			flag = false;
		}

	}
}
