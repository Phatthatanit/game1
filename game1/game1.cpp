
#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1475, 600), "Game from scratch!");

	////// Circle
	/*sf::CircleShape collision(100.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(sf::Color::Red);*/

	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("pic/walk04.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	////// Sprite
	/*sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	shapeSprite.setTextureRect(sf::IntRect(0, 0 ,148 ,350)); */

	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);

	int spriteSizeX = playerTexture.getSize().x / 10 ;
	int spriteSizeY = playerTexture.getSize().y / 1;
	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	int animationFrame = 0;
	float totalTime = 0;
	float deltaTime = 0.0f;
	float speed = 100.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		window.draw(shapeSprite);
		//window.draw(collision);
		window.display();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			shapeSprite.move(speed*deltaTime, 0.f*speed );
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 125));

			
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			shapeSprite.move(-.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		} */
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			shapeSprite.move(0.f*speed, -speed * deltaTime);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 125));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			shapeSprite.move(0.f*speed, speed * deltaTime);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 125));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		totalTime += deltaTime;
		if (totalTime >= 0.1)
		{
			totalTime -= 0.1;
			animationFrame++;
		}

		if (animationFrame >= 9) {
			animationFrame = 0;
		}

		window.clear();
	}
	return 0;
}