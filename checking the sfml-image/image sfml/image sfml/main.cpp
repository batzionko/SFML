#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main()
{
	enum Direction{Down,Left,Right,Up};
	//int sourceX=32, sourceY=Down;//בדיוק אותו דבר כמו השורה מתחת
	sf::Vector2i source(1, Down);
	sf::RenderWindow Window;
	Window.create(sf::VideoMode(800, 600), "my first nisayon");
	Window.setKeyRepeatEnabled(false);
	sf::Texture pTexture;
	sf::Sprite imMoov;
	if (!pTexture.loadFromFile("moov.png"))
	{
		std::cout << "not found!" << std::endl;
	}
	imMoov.setTexture(pTexture);
	imMoov.setPosition(100,100);
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
			case sf::Event::KeyPressed:
				if (Event.key.code == sf::Keyboard::Up)
					source.y = Up;
				else if(Event.key.code == sf::Keyboard::Down)
					source.y = Down;
				else if (Event.key.code == sf::Keyboard::Right)
					source.y = Right;
				else if (Event.key.code == sf::Keyboard::Left)
					source.y = Left;
			}
			source.x++;
			if (source.x * 32 >= pTexture.getSize().x)
				source.x = 0;
			imMoov.setTextureRect(sf::IntRect(source.x * 32, source.y * 46, 32, 46));
			Window.draw(imMoov);
			Window.display();
			Window.clear();
		}
	}

	return EXIT_SUCCESS;
}