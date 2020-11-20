#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <sstream> 
#include "Menu.h"
#include <sstream> 
int p = 3,s =0,sc=0;

int c, n,num=1;
/*void mon() {
	if ( num == 0) {

		for (c = 1; c <= 1; c++) {
			n = rand() % 26 + 1;
			printf("%d\n", n);
			
			Sleep(20);

		}
	}

}*/
int main()
{
	
	//srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1475, 420), "Game!");
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1475.0f, 420.0f));

	Menu menu(window.getSize().x, window.getSize().y);

	int currentScore = 0;

	sf::Font myFont;
	if (!myFont.loadFromFile("pic/score.ttf")) {}

	sf::Text score1;
	score1.setFont(myFont);
	score1.setFillColor(sf::Color::Yellow);
	score1.setStyle(sf::Text::Regular);
	score1.setString("S c o r e : ");
	score1.setCharacterSize(30);
	

	sf::Text scoreCurrent;
	scoreCurrent.setFont(myFont);
	scoreCurrent.setFillColor(sf::Color::Yellow);
	scoreCurrent.setStyle(sf::Text::Regular);
	scoreCurrent.setCharacterSize(30);
	

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

	////// m1
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
	
	////// m2
	sf::Texture m2;
	if (!m2.loadFromFile("pic/b.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem2;
	shapem2.setTexture(m2);
	int spriteSizeX1 = m2.getSize().x / 10;
	int spriteSizeY1 = m2.getSize().y / 1;
	shapem2.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));
	
	////// m3
	sf::Texture m3;
	if (!m3.loadFromFile("pic/c.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem3;
	shapem3.setTexture(m3);
	int spriteSizeX1 = m3.getSize().x / 10;
	int spriteSizeY1 = m3.getSize().y / 1;
	shapem3.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));


	////// m4
	sf::Texture m4;
	if (!m4.loadFromFile("pic/d.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem4;
	shapem4.setTexture(m4);
	int spriteSizeX1 = m4.getSize().x / 10;
	int spriteSizeY1 = m4.getSize().y / 1;
	shapem4.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));


	////// m5
	sf::Texture m5;
	if (!m5.loadFromFile("pic/e.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem5;
	shapem5.setTexture(m5);
	int spriteSizeX1 = m5.getSize().x / 10;
	int spriteSizeY1 = m5.getSize().y / 1;
	shapem5.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));

	///// m6
	sf::Texture m6;
	if (!m6.loadFromFile("pic/e.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem6;
	shapem6.setTexture(m6);
	int spriteSizeX1 = m6.getSize().x / 10;
	int spriteSizeY1 = m6.getSize().y / 1;
	shapem6.setTextureRect(sf::IntRect(0, 0, spriteSizeX1, spriteSizeY1));

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

	////// howto
	sf::Texture howtoTexture;
	sf::RectangleShape howto1(sf::Vector2f(1475.0f, 420.0f));
	howtoTexture.loadFromFile("pic/howto.png");
	howto1.setTexture(&howtoTexture);




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
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::W:
						menu.MoveUp();
						break;

				case sf::Keyboard::S:
					menu.MoveDown();
					break;

					case sf::Keyboard::Return:
						switch (menu.GetPressedItem()) {
						case 0:
							std::cout << "Play has been pressd" << std::endl;
							p = 0;
							num = 0;
							printf("num = %d", num);
							break;
						case 1:
							std::cout << "How to has been pressd" << std::endl;
							p = 4;
							break;
					
						case 2:
							window.close();
							break;
						
							
						}
				}
				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		line.setPosition(shapeSprite.getPosition().x - 120, 139.0f);
		pause.setPosition(shapeSprite.getPosition().x - 450, 160.0f);
		pause1.setPosition(shapeSprite.getPosition().x - 1200.0f, 0.0f);
		score.setPosition(shapeSprite.getPosition().x - 1500, 0.0f);
		score1.setPosition(shapeSprite.getPosition().x - 300, 5.0f);
		scoreCurrent.setPosition(shapeSprite.getPosition().x + 60, 5.0f);
		view.setCenter(shapeSprite.getPosition().x - 400.0f, 210.0f);
		game.setPosition(shapeSprite.getPosition().x - 650, 60.0f);
		shapem1.setPosition(shapeSprite.getPosition().x - 1150, 160.0f);

		deltaTime = clock.restart().asSeconds();
		

		if (p == 1) {
			window.draw(bg);
			window.draw(shapeSprite);
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);
			window.draw(collision);
			window.draw(line);
			window.setView(view);
			window.draw(pause);
			window.draw(pause1);
		}
		if (p == 2) {
			
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);
			window.draw(game);
			
			
		}
		if (p == 3) {
			menu.draw(window);
		}
		if (p == 0) {
			window.draw(bg);
			window.draw(shapeSprite);
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);
			window.draw(collision);
			window.draw(line);
			window.setView(view);
			//window.draw(shapem1);
			//mon();
			
			
			
		}
		if (p == 4) {
			window.draw(howto1);
			
			
		}
		
		window.display();
		
		int xOp = rand() % 500;
		int yOp = rand() % 500;


		std::stringstream scoreShow;
		scoreShow << currentScore;
		scoreCurrent.setString(scoreShow.str().c_str());
		
		

		if (shapeSprite.getPosition().x < 10000 && p == 0) {
			shapeSprite.move(speed * deltaTime, 0.f * speed);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 91));
			shapem1.move(speed* deltaTime, 0.f * speed);
			shapem1.setTextureRect(sf::IntRect(spriteSizeX* animationFrame, spriteSizeY * 0, 110, 110));
			if (p == 0) {
				currentScore += 1;
				Sleep(20);
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (shapeSprite.getPosition().y > 140 && p == 0) {
				shapeSprite.move(0.f * speed, -speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 91));
				
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (shapeSprite.getPosition().y < 356 && p == 0) {
				shapeSprite.move(0.f * speed, speed * deltaTime);
				shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 91));
				
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Right))
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

		
		
		
		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			collision.setPosition(sf::Vector2f(xOp, yOp));
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

