#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main()
{

	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "my first nisayon");
	Window.setKeyRepeatEnabled(false);

	while (Window.isOpen())
	{
		sf::Event Event;
		std::string display = "";
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;

				case sf::Event::MouseEntered:
					std::cout << "in" << std::endl;
					break;
				case sf::Event::MouseLeft:
					std::cout << "out" << std::endl;
				case sf::Event::MouseButtonPressed:
					if (Event.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "X: " <<Event.mouseButton.x<<" Y: "<<Event.mouseButton.y<< std::endl;
					}
				case sf::Event::TextEntered:
					if (Event.text.unicode != 8)
						display += (char)Event.text.unicode;
					else
						display = display.substr(0, display.length() - 1);
					std::cout << display;
					break;
				}
				
			}
			Window.display();
		}


		return EXIT_SUCCESS;
	}