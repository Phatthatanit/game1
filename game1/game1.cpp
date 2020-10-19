
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1475, 600), "Game from scratch!");

	////// Circle
	sf::CircleShape collision(40.f);
	collision.setPosition({ 500.f, 20.f });
	collision.setFillColor(sf::Color::Green);

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

	sf::Vector2f spawnPoint = { 0.f, 0.f };
	shapeSprite.setPosition(spawnPoint);

	int animationFrame = 0;
	float totalTime = 0;
	float deltaTime = 0.0f;
	float speed = 100.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		window.draw(shapeSprite);
		window.draw(collision);
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
		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			Beep(329, 100);
			Beep(493, 100);
			shapeSprite.setPosition(spawnPoint);
			
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