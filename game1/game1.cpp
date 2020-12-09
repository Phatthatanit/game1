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
int p = 3, s = 0, sc = 0, rs = 0;

int num = 1, mon1;


void mons1()
{
	srand(time(NULL));
	mon1 = rand() % 26 + 1;
	printf("%d", mon1);
	for (int nub = 0; nub <= 100000; nub++) {}
	//Sleep(1000);
}




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


	sf::Text myname;
	myname.setFont(myFont);
	myname.setFillColor(sf::Color::Yellow);
	myname.setStyle(sf::Text::Regular);
	myname.setString("63010727 Phattharanit Tesjaroen");
	myname.setCharacterSize(20);

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

	////// player
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
	shapem1.setTextureRect(sf::IntRect(0,0, spriteSizeX1, spriteSizeY1));
	shapem1.setOrigin(0.0f, -270.0f );

	////// m2
	sf::Texture m2;
	if (!m2.loadFromFile("pic/b.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem2;
	shapem2.setTexture(m2);
	int spriteSizeX2 = m2.getSize().x / 10;
	int spriteSizeY2 = m2.getSize().y / 1;
	shapem2.setTextureRect(sf::IntRect(0, 0, spriteSizeX2, spriteSizeY2));
	shapem2.setOrigin(0.0f, -100.0f);

	////// m3
	sf::Texture m3;
	if (!m3.loadFromFile("pic/c.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem3;
	shapem3.setTexture(m3);
	int spriteSizeX3 = m3.getSize().x / 10;
	int spriteSizeY3 = m3.getSize().y / 1;
	shapem3.setTextureRect(sf::IntRect(0, 0, spriteSizeX3, spriteSizeY3));
	shapem3.setOrigin(0.0f, -70.0f);
	////// m4
	sf::Texture m4;
	if (!m4.loadFromFile("pic/d.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem4;
	shapem4.setTexture(m4);
	int spriteSizeX4 = m4.getSize().x / 10;
	int spriteSizeY4 = m4.getSize().y / 1;
	shapem4.setTextureRect(sf::IntRect(0, 0, spriteSizeX4, spriteSizeY4));
	shapem4.setOrigin(0.0f, -90.0f);
	////// m5
	sf::Texture m5;
	if (!m5.loadFromFile("pic/e.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem5;
	shapem5.setTexture(m5);
	int spriteSizeX5 = m5.getSize().x / 10;
	int spriteSizeY5 = m5.getSize().y / 1;
	shapem5.setTextureRect(sf::IntRect(0, 0, spriteSizeX5, spriteSizeY5));
	shapem5.setOrigin(0.0f, -130.0f);

	////// m6
	sf::Texture m6;
	if (!m6.loadFromFile("pic/f.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem6;
	shapem6.setTexture(m6);
	int spriteSizeX6 = m6.getSize().x / 10;
	int spriteSizeY6 = m6.getSize().y / 1;
	shapem6.setTextureRect(sf::IntRect(0, 0, spriteSizeX6, spriteSizeY6));
	shapem6.setOrigin(0.0f, -200.0f);
	////// m7
	sf::Texture m7;
	if (!m7.loadFromFile("pic/g.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem7;
	shapem7.setTexture(m7);
	int spriteSizeX7 = m7.getSize().x / 10;
	int spriteSizeY7 = m7.getSize().y / 1;
	shapem7.setTextureRect(sf::IntRect(0, 0, spriteSizeX7, spriteSizeY7));
	shapem7.setOrigin(0.0f, -70.0f);
	////// m8
	sf::Texture m8;
	if (!m8.loadFromFile("pic/h.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem8;
	shapem8.setTexture(m8);
	int spriteSizeX8 = m8.getSize().x / 10;
	int spriteSizeY8 = m8.getSize().y / 1;
	shapem8.setTextureRect(sf::IntRect(0, 0, spriteSizeX8, spriteSizeY8));
	shapem8.setOrigin(0.0f, -190.0f);
	////// m9
	sf::Texture m9;
	if (!m9.loadFromFile("pic/i.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem9;
	shapem9.setTexture(m9);
	int spriteSizeX9 = m9.getSize().x / 10;
	int spriteSizeY9 = m9.getSize().y / 1;
	shapem9.setTextureRect(sf::IntRect(0, 0, spriteSizeX9, spriteSizeY9));
	shapem9.setOrigin(0.0f, -200.0f);
	////// m10
	sf::Texture m10;
	if (!m10.loadFromFile("pic/j.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem10;
	shapem10.setTexture(m10);
	int spriteSizeX10 = m10.getSize().x / 10;
	int spriteSizeY10 = m10.getSize().y / 1;
	shapem10.setTextureRect(sf::IntRect(0, 0, spriteSizeX10, spriteSizeY10));
	shapem10.setOrigin(0.0f, -260.0f);
	////// m11
	sf::Texture m11;
	if (!m11.loadFromFile("pic/k.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem11;
	shapem11.setTexture(m11);
	int spriteSizeX11 = m11.getSize().x / 10;
	int spriteSizeY11 = m11.getSize().y / 1;
	shapem11.setTextureRect(sf::IntRect(0, 0, spriteSizeX11, spriteSizeY11));
	shapem11.setOrigin(0.0f, -190.0f);
	////// m12
	sf::Texture m12;
	if (!m12.loadFromFile("pic/k.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem12;
	shapem12.setTexture(m12);
	int spriteSizeX12 = m12.getSize().x / 10;
	int spriteSizeY12 = m12.getSize().y / 1;
	shapem12.setTextureRect(sf::IntRect(0, 0, spriteSizeX12, spriteSizeY12));
	shapem12.setOrigin(0.0f, -80.0f);
	////// m13
	sf::Texture m13;
	if (!m13.loadFromFile("pic/l.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem13;
	shapem13.setTexture(m13);
	int spriteSizeX13 = m13.getSize().x / 10;
	int spriteSizeY13 = m13.getSize().y / 1;
	shapem13.setTextureRect(sf::IntRect(0, 0, spriteSizeX13, spriteSizeY13));
	shapem13.setOrigin(0.0f, -200.0f);

	////// m14
	sf::Texture m14;
	if (!m14.loadFromFile("pic/m.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem14;
	shapem14.setTexture(m14);
	int spriteSizeX14 = m14.getSize().x / 10;
	int spriteSizeY14 = m14.getSize().y / 1;
	shapem14.setTextureRect(sf::IntRect(0, 0, spriteSizeX14, spriteSizeY14));
	shapem14.setOrigin(0.0f, -150.0f);
	////// m15
	sf::Texture m15;
	if (!m15.loadFromFile("pic/n.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem15;
	shapem15.setTexture(m15);
	int spriteSizeX15 = m15.getSize().x / 10;
	int spriteSizeY15 = m15.getSize().y / 1;
	shapem15.setTextureRect(sf::IntRect(0, 0, spriteSizeX15, spriteSizeY15));
	shapem15.setOrigin(0.0f, -240.0f);
	////// m16
	sf::Texture m16;
	if (!m16.loadFromFile("pic/o.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem16;
	shapem16.setTexture(m16);
	int spriteSizeX16 = m16.getSize().x / 10;
	int spriteSizeY16 = m16.getSize().y / 1;
	shapem16.setTextureRect(sf::IntRect(0, 0, spriteSizeX16, spriteSizeY16));
	shapem16.setOrigin(0.0f, -170.0f);
	////// m17
	sf::Texture m17;
	if (!m17.loadFromFile("pic/p.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem17;
	shapem17.setTexture(m17);
	int spriteSizeX17 = m17.getSize().x / 10;
	int spriteSizeY17 = m17.getSize().y / 1;
	shapem17.setTextureRect(sf::IntRect(0, 0, spriteSizeX17, spriteSizeY17));
	shapem17.setOrigin(0.0f, -220.0f);
	////// m18
	sf::Texture m18;
	if (!m18.loadFromFile("pic/q.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem18;
	shapem18.setTexture(m18);
	int spriteSizeX18 = m18.getSize().x / 10;
	int spriteSizeY18 = m18.getSize().y / 1;
	shapem18.setTextureRect(sf::IntRect(0, 0, spriteSizeX18, spriteSizeY18));
	shapem18.setOrigin(0.0f, -110.0f);
	////// m19
	sf::Texture m19;
	if (!m19.loadFromFile("pic/r.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem19;
	shapem19.setTexture(m19);
	int spriteSizeX19 = m19.getSize().x / 10;
	int spriteSizeY19 = m19.getSize().y / 1;
	shapem19.setTextureRect(sf::IntRect(0, 0, spriteSizeX19, spriteSizeY19));
	shapem19.setOrigin(0.0f, -240.0f);
	////// m20
	sf::Texture m20;
	if (!m20.loadFromFile("pic/s.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem20;
	shapem20.setTexture(m20);
	int spriteSizeX20 = m20.getSize().x / 10;
	int spriteSizeY20 = m20.getSize().y / 1;
	shapem20.setTextureRect(sf::IntRect(0, 0, spriteSizeX20, spriteSizeY20));
	shapem20.setOrigin(0.0f, -140.0f);
	////// m21
	sf::Texture m21;
	if (!m21.loadFromFile("pic/t.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem21;
	shapem21.setTexture(m21);
	int spriteSizeX21 = m21.getSize().x / 10;
	int spriteSizeY21 = m21.getSize().y / 1;
	shapem21.setTextureRect(sf::IntRect(0, 0, spriteSizeX21, spriteSizeY21));
	shapem21.setOrigin(0.0f, -70.0f);
	////// m22
	sf::Texture m22;
	if (!m22.loadFromFile("pic/u.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem22;
	shapem22.setTexture(m22);
	int spriteSizeX22 = m22.getSize().x / 10;
	int spriteSizeY22 = m22.getSize().y / 1;
	shapem22.setTextureRect(sf::IntRect(0, 0, spriteSizeX22, spriteSizeY22));
	shapem22.setOrigin(0.0f, -180.0f);
	////// m23
	sf::Texture m23;
	if (!m23.loadFromFile("pic/v.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem23;
	shapem23.setTexture(m23);
	int spriteSizeX23 = m23.getSize().x / 10;
	int spriteSizeY23 = m23.getSize().y / 1;
	shapem23.setTextureRect(sf::IntRect(0, 0, spriteSizeX23, spriteSizeY23));
	shapem23.setOrigin(0.0f, -80.0f);
	////// m24
	sf::Texture m24;
	if (!m24.loadFromFile("pic/x.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem24;
	shapem24.setTexture(m24);
	int spriteSizeX24 = m24.getSize().x / 10;
	int spriteSizeY24 = m24.getSize().y / 1;
	shapem24.setTextureRect(sf::IntRect(0, 0, spriteSizeX24, spriteSizeY24));
	shapem24.setOrigin(0.0f, -280.0f);
	////// m25
	sf::Texture m25;
	if (!m25.loadFromFile("pic/y.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem25;
	shapem25.setTexture(m25);
	int spriteSizeX25 = m25.getSize().x / 10;
	int spriteSizeY25 = m25.getSize().y / 1;
	shapem25.setTextureRect(sf::IntRect(0, 0, spriteSizeX25, spriteSizeY25));
	shapem25.setOrigin(0.0f, -100.0f);
	////// m26
	sf::Texture m26;
	if (!m26.loadFromFile("pic/z.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem26;
	shapem26.setTexture(m26);
	int spriteSizeX26 = m26.getSize().x / 10;
	int spriteSizeY26 = m26.getSize().y / 1;
	shapem26.setTextureRect(sf::IntRect(0, 0, spriteSizeX26, spriteSizeY26));
	shapem26.setOrigin(0.0f, -90.0f);

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
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
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
		myname.setPosition(shapeSprite.getPosition().x - 370, 380.0f);
		scoreCurrent.setPosition(shapeSprite.getPosition().x + 60, 5.0f);
		view.setCenter(shapeSprite.getPosition().x - 400.0f, 210.0f);
		game.setPosition(shapeSprite.getPosition().x - 650, 60.0f);
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

			window.draw(game);
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			if (p == 2 && rs == 0) {
				rs = 1;
				printf("%d", rs);
				Sleep(300);

			}
			else {
				p = 2;
				printf("%d", p);
				Sleep(300);

			}
		}
		if (rs == 1) {
			window.close();

		}

		if (p == 3) {
			menu.draw(window);
			window.draw(myname);
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
			mons1();
			

		}
		if (p == 0 && mon1 == 1 ) {
			window.draw(shapem1);
		}
		if (p == 0 && mon1 == 2 ) {
			window.draw(shapem2);
		}
		if (p == 0 && mon1 == 3 ) {
			window.draw(shapem3);
		}
		if (p == 0 && mon1 == 4 ) {
			window.draw(shapem4);
		}
		if (p == 0 && mon1 == 5) {
			window.draw(shapem5);
		}
		if (p == 0 && mon1 == 6) {
			window.draw(shapem6);
		}
		if (p == 0 && mon1 == 7 ) {
			window.draw(shapem7);
		}
		if (p == 0 && mon1 == 8 ) {
			window.draw(shapem8);
		}
		if (p == 0 && mon1 == 9 ) {
			window.draw(shapem9);
		}
		if (p == 0 && mon1 == 10 ) {
			window.draw(shapem10);
		}
		if (p == 0 && mon1 == 11 ) {
			window.draw(shapem11);
		}
		if (p == 0 && mon1 == 12 ) {
			window.draw(shapem12);
		}
		if (p == 0 && mon1 == 13) {
			window.draw(shapem13 );
		}
		if (p == 0 && mon1 == 14 ) {
			window.draw(shapem14);
		}
		if (p == 0 && mon1 == 15 ) {
			window.draw(shapem15);
		}
		if (p == 0 && mon1 == 16 ) {
			window.draw(shapem16);
		}
		if (p == 0 && mon1 == 17 ) {
			window.draw(shapem17);
		}
		if (p == 0 && mon1 == 18 ) {
			window.draw(shapem18);
		}
		if (p == 0 && mon1 == 19 ) {
			window.draw(shapem19);
		}
		if (p == 0 && mon1 == 20 ) {
			window.draw(shapem20);
		}
		if (p == 0 && mon1 == 21 ) {
			window.draw(shapem21);
		}
		if (p == 0 && mon1 == 22 ) {
			window.draw(shapem22);
		}
		if (p == 0 && mon1 == 23 ) {
			window.draw(shapem23);
		}
		if (p == 0 && mon1 == 24 ) {
			window.draw(shapem24);
		}
		if (p == 0 && mon1 == 25 ) {
			window.draw(shapem25);
		}
		if (p == 0 && mon1 == 26 ) {
			window.draw(shapem26);
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
			shapem1.move(speed * 0.05f, 0.f * speed);
			shapem1.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem2.move(speed * 0.05f, 0.f * speed);
			shapem2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem3.move(speed * 0.05f, 0.f * speed);
			shapem3.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem4.move(speed * 0.05f, 0.f * speed);
			shapem4.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem5.move(speed * 0.05f, 0.f * speed);
			shapem5.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem6.move(speed * 0.05f, 0.f * speed);
			shapem6.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem7.move(speed * 0.05f, 0.f * speed);
			shapem7.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem8.move(speed * 0.05f, 0.f * speed);
			shapem8.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem9.move(speed * 0.05f, 0.f * speed);
			shapem9.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem10.move(speed * 0.05f, 0.f * speed);
			shapem10.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem11.move(speed * 0.05f, 0.f * speed);
			shapem11.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem12.move(speed * 0.05f, 0.f * speed);
			shapem12.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem13.move(speed * 0.05f, 0.f * speed);
			shapem13.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem14.move(speed * 0.05f, 0.f * speed);
			shapem14.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem15.move(speed * 0.05f, 0.f * speed);
			shapem15.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem16.move(speed * 0.05f, 0.f * speed);
			shapem16.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem17.move(speed * 0.05f, 0.f * speed);
			shapem17.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem18.move(speed * 0.05f, 0.f * speed);
			shapem18.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem19.move(speed * 0.05f, 0.f * speed);
			shapem19.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem20.move(speed * 0.05f, 0.f * speed);
			shapem20.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem21.move(speed * 0.05f, 0.f * speed);
			shapem21.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem22.move(speed * 0.05f, 0.f * speed);
			shapem22.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem23.move(speed * 0.05f, 0.f * speed);
			shapem23.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem24.move(speed * 0.05f, 0.f * speed);
			shapem24.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem25.move(speed * 0.05f, 0.f * speed);
			shapem25.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
			shapem26.move(speed * 0.05f, 0.f * speed);
			shapem26.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));



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




		if (line.getGlobalBounds().intersects(shapem1.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem2.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem3.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem4.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem5.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem6.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem7.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem8.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem9.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem10.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem11.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem12.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem13.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem14.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem15.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem16.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem17.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem18.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem19.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem20.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem21.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem22.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem23.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem24.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem25.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0) {
				p = 2;


				printf("%d", p);
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem26.getGlobalBounds())) {
			line.setPosition(sf::Vector2f(xOp, yOp));
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