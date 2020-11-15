#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include <sstream> 
int p = 0,s =0;
int main()
{

	sf::RenderWindow window(sf::VideoMode(1475, 420), "Game from scratch!");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1475.0f, 420.0f));

	int currentScore = 0;

	sf::Font myFont;
	if (!myFont.loadFromFile("pic/score.ttf")) {}

	sf::Text score1;
	score1.setFont(myFont);
	score1.setFillColor(sf::Color::Yellow);
	score1.setStyle(sf::Text::Regular);
	score1.setString("S c o r e : ");
	score1.setCharacterSize(30);
	score1.setPosition(800, 100);

	sf::Text scoreCurrent;
	scoreCurrent.setFont(myFont);
	scoreCurrent.setFillColor(sf::Color::Yellow);
	scoreCurrent.setStyle(sf::Text::Regular);
	scoreCurrent.setString(" 0 ");
	scoreCurrent.setCharacterSize(30);
	scoreCurrent.setPosition(1200, 0);

	//soundstart

	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("pic/s3.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Sound sound;
	sound.setLoop(true);
	sound.setBuffer(buffer);
	sound.play();


	//soundend
	
		sf::SoundBuffer buffer1;
		if (!buffer1.loadFromFile("pic/s4.ogg"))
		{
			std::cout << "Load failed" << std::endl;
		}
		sf::Sound sound1;
		sound1.setBuffer(buffer1);
		
	




	////// Circle
	sf::CircleShape collision(40.f);
	collision.setPosition({ 1800.f, 210.f });
	collision.setFillColor(sf::Color::Green);

	///// line

	sf::RectangleShape line(sf::Vector2f(10, 260));
	line.setFillColor(sf::Color::Red);

	////// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("pic/walk.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	int spriteSizeX = playerTexture.getSize().x / 10;
	int spriteSizeY = playerTexture.getSize().y / 1;
	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	shapeSprite.setOrigin(120.0f / 2.0f, 125.0f / 2.0f);

	/*////// m1
	sf::Texture m1;
	if (!m1.loadFromFile("pic/a.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem1;
	shapem1.setTexture(m1);
	int spriteSizeX1 = m1.getSize().x / 10;
	int spriteSizeY1 = m1.getSize().y / 1;
	shapem1.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));
	shapem1.setOrigin(120.0f / 2.0f, 125.0f / 2.0f);
	*/

	////// bg2
	sf::Texture bgTexture;
	sf::RectangleShape bg(sf::Vector2f(10000.0f, 420.0f));
	bgTexture.loadFromFile("pic/bg2.png");
	bg.setTexture(&bgTexture);

	sf::Vector2f spawnPoint = { 1200.f, 210.f };
	shapeSprite.setPosition(spawnPoint);

	////// pause
	sf::Texture pauseTexture;
	sf::RectangleShape pause(sf::Vector2f(100.0f, 100.0f));
	pauseTexture.loadFromFile("pic/pause1.png");
	pause.setTexture(&pauseTexture);

	////// pause1
	sf::Color pauseColor(0, 0, 0, 100);
	sf::RectangleShape pause1(sf::Vector2f(1575, 420));
	pause1.setFillColor(pauseColor);

	////// gameover
	sf::Texture gameTexture;
	sf::RectangleShape game(sf::Vector2f(500.0f, 300.0f));
	gameTexture.loadFromFile("pic/gameov1.png");
	game.setTexture(&gameTexture);




	////// score
	sf::Color scoreColor(0, 0, 0, 1000);
	sf::RectangleShape score(sf::Vector2f(2000, 50));
	score.setFillColor(scoreColor);

	int animationFrame = 0;
	float totalTime = 0;
	float deltaTime = 0.0f;
	float speed = 100.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		line.setPosition(shapeSprite.getPosition().x - 120, 139.0f);
		pause.setPosition(shapeSprite.getPosition().x - 450, 160.0f);
		pause1.setPosition(shapeSprite.getPosition().x - 1200.0f, 0.0f);
		score.setPosition(shapeSprite.getPosition().x - 1500, 0.0f);
		score1.setPosition(shapeSprite.getPosition().x - 250, 5.0f);
		scoreCurrent.setPosition(shapeSprite.getPosition().x + 60, 5.0f);
		view.setCenter(shapeSprite.getPosition().x - 400.0f, 210.0f);
		game.setPosition(shapeSprite.getPosition().x - 650, 60.0f);

		deltaTime = clock.restart().asSeconds();
		window.setView(view);
		window.draw(bg);
		window.draw(score);
		window.draw(shapeSprite);
		window.draw(line);
		window.draw(collision);
		window.draw(score1);
		window.draw(scoreCurrent);

		if (p == 1) {
			window.draw(pause);
			window.draw(pause1);
		}
		if (p == 2) {
			window.draw(pause1);
			window.draw(game);
			
		}

		window.display();

		if (shapeSprite.getPosition().x < 10000 && p == 0) {
			shapeSprite.move(speed * deltaTime, 0.f * speed);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 91));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (shapeSprite.getPosition().y > 130 && p == 0) {
				shapeSprite.move(0.f * speed, -speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 91));
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (shapeSprite.getPosition().y < 336 && p == 0) {
				shapeSprite.move(0.f * speed, speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 120, 91));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (p == 0) {
				p = 1;
				printf("%d", p);
				Sleep(300);

			}
			else {
				p = 0;
				printf("%d", p);
				Sleep(300);

			}
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			p = 0;
			printf("%d",p);
		}*/

		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			
			if (p == 0) {
				p = 2;
				printf("%d", p);
				sound.stop();
				sound1.play();
				
			}
			

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