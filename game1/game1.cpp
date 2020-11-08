#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
int p = 0;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1475, 420), "Game from scratch!");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1475.0f, 420.0f));

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("pic/s3.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Sound sound;
	sound.setLoop(true);
	sound.setBuffer(buffer);
	sound.play();


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
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	int spriteSizeX = playerTexture.getSize().x / 10;
	int spriteSizeY = playerTexture.getSize().y / 1;
	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	shapeSprite.setOrigin(120.0f / 2.0f, 125.0f / 2.0f);

	////// bg01
	sf::Texture bgTexture;
	if (!bgTexture.loadFromFile("pic/bg01.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::RectangleShape bg(sf::Vector2f(10000.0f, 420.0f));
	bgTexture.loadFromFile("pic/1bg.png");
	bg.setTexture(&bgTexture);

	sf::Vector2f spawnPoint = { 1200.f, 210.f };
	shapeSprite.setPosition(spawnPoint);


	int animationFrame = 0;
	float totalTime = 0;
	float deltaTime = 0.0f;
	float speed = 100.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		view.setCenter(shapeSprite.getPosition().x - 400.0f, 210.0f);

		deltaTime = clock.restart().asSeconds();
		window.setView(view);
		window.draw(bg);
		window.draw(shapeSprite);
		window.draw(collision);
		window.display();
	
		if (shapeSprite.getPosition().x < 10000 && p == 0) {
		shapeSprite.move(speed* deltaTime, 0.f * speed);
		shapeSprite.setTextureRect(sf::IntRect(spriteSizeX* animationFrame, spriteSizeY * 0, 120, 125));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (shapeSprite.getPosition().y > 40 && p == 0) {
				shapeSprite.move(0.f * speed, -speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 125));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (shapeSprite.getPosition().y < 380 && p==0) {
				shapeSprite.move(0.f * speed, speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 125));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (p == 0) {
				p = 1;
				printf("%d", p);
				Sleep(200);
			}
			else {
				p = 0;
				printf("%d", p);
				Sleep(200);

			}
		}

		
		

		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			Beep(329, 100);
			Beep(493, 100);
			shapeSprite.setPosition(spawnPoint);

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
