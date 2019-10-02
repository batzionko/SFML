#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main()
{
	enum Direction { Down, Left, Right, Up };
	//int sourceX=32, sourceY=Down;//בדיוק אותו דבר כמו השורה מתחת
	sf::Vector2i source(1, Down);
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "my first nisayon");
	Window.setKeyRepeatEnabled(false);
	sf::Texture pTexture;
	sf::Sprite imMoov;
	sf::Clock Clock;
	if (!pTexture.loadFromFile("moved.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	imMoov.setTexture(pTexture);
	imMoov.setPosition(100, 100);
	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;


			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			source.y = Left;
			imMoov.move(-1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			source.y = Right;
			imMoov.move(1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			source.y = Down;
			imMoov.move(0, 1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			source.y = Up;
			imMoov.move(0, -1);
		}
		frameCounter += frameSpeed*Clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			source.x++;
			if (source.x * 40 >= 120)
				source.x = 0;
		}
		imMoov.setTextureRect(sf::IntRect(source.x * 40, source.y * 40, 40, 40));
		Window.draw(imMoov);
		Window.display();
		Window.clear();
	}

	return EXIT_SUCCESS;
}