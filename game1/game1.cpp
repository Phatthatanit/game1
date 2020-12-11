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
#include <vector>
#include <algorithm>
#include "Textbox.h"
#include <string>
#include <utility>
#include <iostream>

using namespace std;

int p = 3, s = 0, sc = 0, rs = 0, n = 1, cheak,ckname=0;
float speedmon = 0.03f, plusspeed = 0.01f;
struct input
{
	int deletesp = 0;
} dmon[26];

int num = 1, mon[5];


void mons1()
{
	srand(time(NULL));
	for (; n <= 5; n++) {
		mon[n] = rand() % 26 + 1;
		printf("%d\t", mon[n]);
	}


}

void showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::White);
	window.draw(text);
}

int main()
{
	FILE* fp;
	char temp[255];
	int highscore[6];
	string name[6];
	vector<pair<int, string>>userScore;

	int j = 0;
	int k = false;
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
	if (!buffer.loadFromFile("pic/play.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Sound sound;

	sound.setLoop(true);
	sound.setBuffer(buffer);
	//sound.play();



	//soundend

	sf::SoundBuffer buffer1;
	if (!buffer1.loadFromFile("pic/s4.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sound sound1;
	sound1.setBuffer(buffer1);

	//sounditem

	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("pic/getitemcut.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sound sound2;
	sound2.setBuffer(buffer2);

	//soundkill

	sf::SoundBuffer buffer3;
	if (!buffer3.loadFromFile("pic/killcut.ogg"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sound sound3;
	sound3.setBuffer(buffer3);


	/*////// Circle
	sf::CircleShape collision(40.f);
	collision.setPosition({ 1400.f, 210.f });
	collision.setFillColor(sf::Color::Green);
	*/
	///// line

	sf::RectangleShape line(sf::Vector2f(10, 260));
	line.setFillColor(sf::Color::Red);

	////// it1
	sf::Texture item1;
	sf::RectangleShape it1(sf::Vector2f(60.0f, 60.0f));
	item1.loadFromFile("pic/it5.png");
	it1.setTexture(&item1);
	it1.setPosition({ 1400.f, 210.f });


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
	int dt = 20;
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
	shapem1.setOrigin(shapeSprite.getPosition().x - dt, -270.0f);


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
	shapem2.setOrigin(shapeSprite.getPosition().x - dt, -100.0f);

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
	shapem3.setOrigin(shapeSprite.getPosition().x - dt, -70.0f);
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
	shapem4.setOrigin(shapeSprite.getPosition().x - dt, -90.0f);
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
	shapem5.setOrigin(shapeSprite.getPosition().x - dt, -130.0f);

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
	shapem6.setOrigin(shapeSprite.getPosition().x - dt, -200.0f);
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
	shapem7.setOrigin(shapeSprite.getPosition().x - dt, -70.0f);
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
	shapem8.setOrigin(shapeSprite.getPosition().x - dt, -190.0f);
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
	shapem9.setOrigin(shapeSprite.getPosition().x - dt, -200.0f);
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
	shapem10.setOrigin(shapeSprite.getPosition().x - dt, -260.0f);
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
	shapem11.setOrigin(shapeSprite.getPosition().x - dt, -190.0f);

	////// m12
	sf::Texture m12;
	if (!m12.loadFromFile("pic/l.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem12;
	shapem12.setTexture(m12);
	int spriteSizeX12 = m12.getSize().x / 10;
	int spriteSizeY12 = m12.getSize().y / 1;
	shapem12.setTextureRect(sf::IntRect(0, 0, spriteSizeX12, spriteSizeY12));
	shapem12.setOrigin(shapeSprite.getPosition().x - dt, -200.0f);

	////// m13
	sf::Texture m13;
	if (!m13.loadFromFile("pic/m.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem13;
	shapem13.setTexture(m13);
	int spriteSizeX13 = m13.getSize().x / 10;
	int spriteSizeY13 = m13.getSize().y / 1;
	shapem13.setTextureRect(sf::IntRect(0, 0, spriteSizeX13, spriteSizeY13));
	shapem13.setOrigin(shapeSprite.getPosition().x - dt, -150.0f);
	////// m14
	sf::Texture m14;
	if (!m14.loadFromFile("pic/n.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem14;
	shapem14.setTexture(m14);
	int spriteSizeX14 = m14.getSize().x / 10;
	int spriteSizeY14 = m14.getSize().y / 1;
	shapem14.setTextureRect(sf::IntRect(0, 0, spriteSizeX14, spriteSizeY14));
	shapem14.setOrigin(shapeSprite.getPosition().x - dt, -240.0f);

	////// m15
	sf::Texture m15;
	if (!m15.loadFromFile("pic/o.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem15;
	shapem15.setTexture(m15);
	int spriteSizeX15 = m15.getSize().x / 10;
	int spriteSizeY15 = m15.getSize().y / 1;
	shapem15.setTextureRect(sf::IntRect(0, 0, spriteSizeX15, spriteSizeY15));
	shapem15.setOrigin(shapeSprite.getPosition().x - dt, -170.0f);

	////// m16
	sf::Texture m16;
	if (!m16.loadFromFile("pic/p.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem16;
	shapem16.setTexture(m16);
	int spriteSizeX16 = m16.getSize().x / 10;
	int spriteSizeY16 = m16.getSize().y / 1;
	shapem16.setTextureRect(sf::IntRect(0, 0, spriteSizeX16, spriteSizeY16));
	shapem16.setOrigin(shapeSprite.getPosition().x - dt, -220.0f);
	////// m17
	sf::Texture m17;
	if (!m17.loadFromFile("pic/q.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem17;
	shapem17.setTexture(m17);
	int spriteSizeX17 = m17.getSize().x / 10;
	int spriteSizeY17 = m17.getSize().y / 1;
	shapem17.setTextureRect(sf::IntRect(0, 0, spriteSizeX17, spriteSizeY17));
	shapem17.setOrigin(shapeSprite.getPosition().x - dt, -110.0f);
	////// m18
	sf::Texture m18;
	if (!m18.loadFromFile("pic/r.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem18;
	shapem18.setTexture(m18);
	int spriteSizeX18 = m18.getSize().x / 10;
	int spriteSizeY18 = m18.getSize().y / 1;
	shapem18.setTextureRect(sf::IntRect(0, 0, spriteSizeX18, spriteSizeY18));
	shapem18.setOrigin(shapeSprite.getPosition().x - dt, -240.0f);
	////// m19
	sf::Texture m19;
	if (!m19.loadFromFile("pic/s.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem19;
	shapem19.setTexture(m19);
	int spriteSizeX19 = m19.getSize().x / 10;
	int spriteSizeY19 = m19.getSize().y / 1;
	shapem19.setTextureRect(sf::IntRect(0, 0, spriteSizeX19, spriteSizeY19));
	shapem19.setOrigin(shapeSprite.getPosition().x - dt, -140.0f);
	////// m20
	sf::Texture m20;
	if (!m20.loadFromFile("pic/t.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem20;
	shapem20.setTexture(m20);
	int spriteSizeX20 = m20.getSize().x / 10;
	int spriteSizeY20 = m20.getSize().y / 1;
	shapem20.setTextureRect(sf::IntRect(0, 0, spriteSizeX20, spriteSizeY20));
	shapem20.setOrigin(shapeSprite.getPosition().x - dt, -70.0f);
	////// m21
	sf::Texture m21;
	if (!m21.loadFromFile("pic/u.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem21;
	shapem21.setTexture(m21);
	int spriteSizeX21 = m21.getSize().x / 10;
	int spriteSizeY21 = m21.getSize().y / 1;
	shapem21.setTextureRect(sf::IntRect(0, 0, spriteSizeX21, spriteSizeY21));
	shapem21.setOrigin(shapeSprite.getPosition().x - dt, -180.0f);
	////// m22
	sf::Texture m22;
	if (!m22.loadFromFile("pic/v.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem22;
	shapem22.setTexture(m22);
	int spriteSizeX22 = m22.getSize().x / 10;
	int spriteSizeY22 = m22.getSize().y / 1;
	shapem22.setTextureRect(sf::IntRect(0, 0, spriteSizeX22, spriteSizeY22));
	shapem22.setOrigin(shapeSprite.getPosition().x - dt, -80.0f);
	////// m23
	sf::Texture m23;
	if (!m23.loadFromFile("pic/w.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Sprite shapem23;
	shapem23.setTexture(m23);
	int spriteSizeX23 = m23.getSize().x / 10;
	int spriteSizeY23 = m23.getSize().y / 1;
	shapem23.setTextureRect(sf::IntRect(0, 0, spriteSizeX23, spriteSizeY23));
	shapem23.setOrigin(shapeSprite.getPosition().x - dt, -80.0f);
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
	shapem24.setOrigin(shapeSprite.getPosition().x - dt, -280.0f);
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
	shapem25.setOrigin(shapeSprite.getPosition().x - dt, -100.0f);
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
	shapem26.setOrigin(shapeSprite.getPosition().x - dt, -90.0f);

	////// bg2
	sf::Texture bgTexture;
	sf::RectangleShape bg(sf::Vector2f(10000.0f, 420.0f));
	bgTexture.loadFromFile("pic/bg2.png");
	bg.setTexture(&bgTexture);


	sf::Vector2f spawnPoint = { 1200.f, 210.f };
	shapeSprite.setPosition(spawnPoint);

	////// pause
	sf::Texture pauseTexture;
	sf::RectangleShape pause(sf::Vector2f(700.0f, 100.0f));
	pauseTexture.loadFromFile("pic/pause2.png");
	pause.setTexture(&pauseTexture);

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

	//textbox
	Textbox playernametextbox(20, sf::Color::White, true);
	playernametextbox.setFont(myFont);
	playernametextbox.setPosition({ 0.0f,150.0f });
	playernametextbox.setlimit(true, 10);

	fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &highscore[i]);
		userScore.push_back(make_pair(highscore[i], name[i]));
	}
	fclose(fp);

	//high scores func

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::TextEntered:
				playernametextbox.typeOn(event);
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
						name[5] = playernametextbox.gettext();
						p = 0;
						num = 0;
						printf("num = %d", num);
						break;
					case 1:
						std::cout << "How to has been pressd" << std::endl;
						p = 4;
						cheak = 1;
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
		line.setPosition(shapeSprite.getPosition().x - 220, 139.0f);
		pause.setPosition(shapeSprite.getPosition().x - 750, 160.0f);
		score.setPosition(shapeSprite.getPosition().x - 1500, 0.0f);
		score1.setPosition(shapeSprite.getPosition().x - 300, 5.0f);
		myname.setPosition(shapeSprite.getPosition().x - 370, 380.0f);
		scoreCurrent.setPosition(shapeSprite.getPosition().x + 60, 5.0f);
		view.setCenter(shapeSprite.getPosition().x - 400.0f, 210.0f);
		game.setPosition(shapeSprite.getPosition().x - 650, 60.0f);
		deltaTime = clock.restart().asSeconds();


		if (p == 1) {

			window.setView(view);
			window.draw(pause);


		}
		if (p == 2 && cheak == 2) {

			window.draw(game);
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);
			if (k == false) {
				j++;

				k = true;
			}


			fp = fopen("./score.txt", "r");
			highscore[5] = currentScore;
			userScore.push_back(make_pair(highscore[5], name[5]));
			sort(userScore.begin(), userScore.end());
			fclose(fp);
			fopen("./score.txt", "w");
			for (int i = 4 + j; i >= 0 + j; i--) {
				strcpy(temp, userScore[i].second.c_str());
				fprintf(fp, "%s %d\n", temp, userScore[i].first);
			}
			fclose(fp);

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

			playernametextbox.drawTo(window);

			showhighscore(0, 30, to_string(userScore[0].first), window, &myFont);
			showhighscore(120, 30, userScore[0].second, window, &myFont);
			showhighscore(0, 50, to_string(userScore[1].first), window, &myFont);
			showhighscore(120, 50, userScore[1].second, window, &myFont);
			showhighscore(0, 70, to_string(userScore[2].first), window, &myFont);
			showhighscore(120, 70, userScore[2].second, window, &myFont);
			showhighscore(0, 90, to_string(userScore[3].first), window, &myFont);
			showhighscore(120, 90, userScore[3].second, window, &myFont);
			showhighscore(0, 110, to_string(userScore[4].first), window, &myFont);
			showhighscore(120, 110, userScore[4].second, window, &myFont);
		}
		if (p == 0 && num == 0) {
			window.draw(bg);
			window.draw(shapeSprite);
			window.draw(score);
			window.draw(score1);
			window.draw(scoreCurrent);
			//window.draw(collision);
			window.draw(line);
			window.draw(it1);
			window.setView(view);

			for (s = 0; s <= 1; s++)
			{
				mons1();
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				p = 0;
			}

			if (mon[1] == 1 || mon[2] == 1 || mon[3] == 1 || mon[4] == 1 || mon[5] == 1) {
				shapem1.move(speed * (speedmon + 0.023f), 0.f * speed);
				shapem1.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					if (dmon[1].deletesp == 0) {
						dmon[1].deletesp = 1;
						sound3.play();

						if (mon[1] == 1) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;

						}
						if (mon[2] == 1) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 1) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 1) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 1) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 2 || mon[2] == 2 || mon[3] == 2 || mon[4] == 2 || mon[5] == 2) {
				shapem2.move(speed * (speedmon + 0.012f), 0.f * speed);
				shapem2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
					if (dmon[2].deletesp == 0) {
						dmon[2].deletesp = 1;
						sound3.play();
						if (mon[1] == 2) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 2) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 2) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 2) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 2) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}

					}
				}
			}
			if (mon[1] == 3 || mon[2] == 3 || mon[3] == 3 || mon[4] == 3 || mon[5] == 3) {
				shapem3.move(speed * (speedmon + 0.013f), 0.f * speed);
				shapem3.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {

					if (dmon[3].deletesp == 0) {
						dmon[3].deletesp = 1;
						sound3.play();
						if (mon[1] == 3) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 3) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 3) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 3) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 3) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 4 || mon[2] == 4 || mon[3] == 4 || mon[4] == 4 || mon[5] == 4) {
				shapem4.move(speed * (speedmon + 0.017f), 0.f * speed);
				shapem4.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					if (dmon[4].deletesp == 0) {
						dmon[4].deletesp = 1;
						sound3.play();
						if (mon[1] == 4) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 4) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 4) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 4) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 4) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 5 || mon[2] == 5 || mon[3] == 5 || mon[4] == 5 || mon[5] == 5) {
				shapem5.move(speed * (speedmon + 0.019f), 0.f * speed);
				shapem5.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
					if (dmon[5].deletesp == 0) {
						dmon[5].deletesp = 1;
						sound3.play();
						if (mon[1] == 5) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 5) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 5) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 5) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 5) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 6 || mon[2] == 6 || mon[3] == 6 || mon[4] == 6 || mon[5] == 6) {
				shapem6.move(speed * (speedmon + 0.029f), 0.f * speed);
				shapem6.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
					if (dmon[6].deletesp == 0) {
						dmon[6].deletesp = 1;
						sound3.play();
						if (mon[1] == 6) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 6) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 6) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 6) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 6) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 7 || mon[2] == 7 || mon[3] == 7 || mon[4] == 7 || mon[5] == 7) {
				shapem7.move(speed * (speedmon + 0.018f), 0.f * speed);
				shapem7.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
					if (dmon[7].deletesp == 0) {
						dmon[7].deletesp = 1;
						sound3.play();
						if (mon[1] == 7) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 7) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 7) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 7) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 7) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 8 || mon[2] == 8 || mon[3] == 8 || mon[4] == 8 || mon[5] == 8) {
				shapem8.move(speed * (speedmon + 0.024f), 0.f * speed);
				shapem8.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
					if (dmon[8].deletesp == 0) {
						dmon[8].deletesp = 1;
						sound3.play();
						if (mon[1] == 8) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 8) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 8) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 8) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 8) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 9 || mon[2] == 9 || mon[3] == 9 || mon[4] == 9 || mon[5] == 9) {
				shapem9.move(speed * (speedmon + 0.021f), 0.f * speed);
				shapem9.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
					if (dmon[9].deletesp == 0) {
						dmon[9].deletesp = 1;
						sound3.play();
						if (mon[1] == 9) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 9) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 9) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 9) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 9) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 10 || mon[2] == 10 || mon[3] == 10 || mon[4] == 10 || mon[5] == 10) {
				shapem10.move(speed * (speedmon + 0.011f), 0.f * speed);
				shapem10.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
					if (dmon[10].deletesp == 0) {
						dmon[10].deletesp = 1;
						sound3.play();
						if (mon[1] == 10) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 10) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 10) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 10) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 10) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 11 || mon[2] == 11 || mon[3] == 11 || mon[4] == 11 || mon[5] == 11) {
				shapem11.move(speed * (speedmon + 0.015f), 0.f * speed);
				shapem11.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
					if (dmon[11].deletesp == 0) {
						dmon[11].deletesp = 1;
						sound3.play();
						if (mon[1] == 11) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 11) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 11) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 11) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 11) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}

					}
				}
			}

			if ((mon[1] == 12 || mon[2] == 12 || mon[3] == 12 || mon[4] == 12 || mon[5] == 12)) {
				shapem12.move(speed * (speedmon + 0.023f), 0.f * speed);
				shapem12.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
					if (dmon[12].deletesp == 0) {
						dmon[12].deletesp = 1;
						sound3.play();
						if (mon[1] == 12) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 12) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 12) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 12) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 12) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 13 || mon[2] == 13 || mon[3] == 13 || mon[4] == 13 || mon[5] == 13) {
				shapem13.move(speed * (speedmon + 0.009f), 0.f * speed);
				shapem13.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
					if (dmon[13].deletesp == 0) {
						dmon[13].deletesp = 1;
						sound3.play();
						if (mon[1] == 13) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 13) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 13) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 13) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 13) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 14 || mon[2] == 14 || mon[3] == 14 || mon[4] == 14 || mon[5] == 14) {
				shapem14.move(speed * (speedmon + 0.027f), 0.f * speed);
				shapem14.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
					if (dmon[14].deletesp == 0) {
						dmon[14].deletesp = 1;
						sound3.play();
						if (mon[1] == 14) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 14) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 14) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 14) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 14) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 15 || mon[2] == 15 || mon[3] == 15 || mon[4] == 15 || mon[5] == 15) {
				shapem15.move(speed * (speedmon + 0.022f), 0.f * speed);
				shapem15.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
					if (dmon[15].deletesp == 0) {
						dmon[15].deletesp = 1;
						sound3.play();
						if (mon[1] == 15) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 15) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 15) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 15) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 15) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 16 || mon[2] == 16 || mon[3] == 16 || mon[4] == 16 || mon[5] == 16) {
				shapem16.move(speed * (speedmon + 0.033f), 0.f * speed);
				shapem16.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
					if (dmon[16].deletesp == 0) {
						dmon[16].deletesp = 1;
						sound3.play();
						if (mon[1] == 16) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 16) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 16) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 16) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 16) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 17 || mon[2] == 17 || mon[3] == 17 || mon[4] == 17 || mon[5] == 17) {
				shapem17.move(speed * (speedmon + 0.004f), 0.f * speed);
				shapem17.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					if (dmon[17].deletesp == 0) {
						dmon[17].deletesp = 1;
						sound3.play();
						if (mon[1] == 17) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 17) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 17) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 17) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 17) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 18 || mon[2] == 18 || mon[3] == 18 || mon[4] == 18 || mon[5] == 18) {
				shapem18.move(speed * (speedmon + 0.008f), 0.f * speed);
				shapem18.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					if (dmon[18].deletesp == 0) {
						dmon[18].deletesp = 1;
						sound3.play();
						if (mon[1] == 18) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 18) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 18) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 18) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 18) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 19 || mon[2] == 19 || mon[3] == 19 || mon[4] == 19 || mon[5] == 19) {
				shapem19.move(speed * (speedmon + 0.020f), 0.f * speed);
				shapem19.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					if (dmon[19].deletesp == 0) {
						dmon[19].deletesp = 1;
						sound3.play();
						if (mon[1] == 19) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 19) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 19) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 19) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 19) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 20 || mon[2] == 20 || mon[3] == 20 || mon[4] == 20 || mon[5] == 20) {
				shapem20.move(speed * (speedmon + 0.014f), 0.f * speed);
				shapem20.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
					if (dmon[20].deletesp == 0) {
						dmon[20].deletesp = 1;
						sound3.play();
						if (mon[1] == 20) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 20) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 20) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 20) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 20) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 21 || mon[2] == 21 || mon[3] == 21 || mon[4] == 21 || mon[5] == 21) {
				shapem21.move(speed * (speedmon + 0.019f), 0.f * speed);
				shapem21.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
					if (dmon[21].deletesp == 0) {
						dmon[21].deletesp = 1;
						sound3.play();
						if (mon[1] == 21) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 21) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 21) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 21) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 21) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 22 || mon[2] == 22 || mon[3] == 22 || mon[4] == 22 || mon[5] == 22) {
				shapem22.move(speed * (speedmon + 0.014f), 0.f * speed);
				shapem22.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
					if (dmon[22].deletesp == 0) {
						dmon[22].deletesp = 1;
						sound3.play();
						if (mon[1] == 22) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 22) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 22) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 22) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 22) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 23 || mon[2] == 23 || mon[3] == 23 || mon[4] == 23 || mon[5] == 23) {
				shapem23.move(speed * (speedmon + 0.004f), 0.f * speed);
				shapem23.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					if (dmon[23].deletesp == 0) {
						dmon[23].deletesp = 1;
						sound3.play();
						if (mon[1] == 23) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 23) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 23) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 23) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 23) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 24 || mon[2] == 24 || mon[3] == 24 || mon[4] == 24 || mon[5] == 24) {
				shapem24.move(speed * (speedmon + 0.024f), 0.f * speed);
				shapem24.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
					if (dmon[24].deletesp == 0) {
						dmon[24].deletesp = 1;
						sound3.play();
						if (mon[1] == 24) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 24) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 24) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 24) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 24) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 25 || mon[2] == 25 || mon[3] == 25 || mon[4] == 25 || mon[5] == 25) {
				shapem25.move(speed * (speedmon + 0.004f), 0.f * speed);
				shapem25.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
					if (dmon[25].deletesp == 0) {
						dmon[25].deletesp = 1;
						sound3.play();
						if (mon[1] == 25) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 25) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 25) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 25) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 25) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}
					}
				}
			}

			if (mon[1] == 26 || mon[2] == 26 || mon[3] == 26 || mon[4] == 26 || mon[5] == 26) {
				shapem26.move(speed * (speedmon + 0.004f), 0.f * speed);
				shapem26.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 110));
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
					if (dmon[26].deletesp == 0) {
						dmon[26].deletesp = 1;
						sound3.play();
						if (mon[1] == 26) {
							mon[1] = rand() % 26 + 1;
							printf("%d\t", mon[1]);
							speedmon += plusspeed;
						}
						if (mon[2] == 26) {
							mon[2] = rand() % 26 + 1;
							printf("%d\t", mon[2]);
							speedmon += plusspeed;
						}
						if (mon[3] == 26) {
							mon[3] = rand() % 26 + 1;
							printf("%d\t", mon[3]);
							speedmon += plusspeed;
						}
						if (mon[4] == 26) {
							mon[4] = rand() % 26 + 1;
							printf("%d\t", mon[4]);
							speedmon += plusspeed;
						}
						if (mon[5] == 26) {
							mon[5] = rand() % 26 + 1;
							printf("%d\t", mon[5]);
							speedmon += plusspeed;
						}

					}
				}
			}
		}




		if (dmon[1].deletesp != 1) {
			if (p == 0 && mon[1] == 1) {
				window.draw(shapem1);
			}
			if (p == 0 && mon[2] == 1) {
				window.draw(shapem1);
			}
			if (p == 0 && mon[3] == 1) {
				window.draw(shapem1);
			}
			if (p == 0 && mon[4] == 1) {
				window.draw(shapem1);
			}
			if (p == 0 && mon[5] == 1) {
				window.draw(shapem1);
			}
		}

		if (dmon[2].deletesp != 1) {
			if (p == 0 && mon[1] == 2) {
				window.draw(shapem2);
			}
			if (p == 0 && mon[2] == 2) {
				window.draw(shapem2);
			}
			if (p == 0 && mon[3] == 2) {
				window.draw(shapem2);
			}
			if (p == 0 && mon[4] == 2) {
				window.draw(shapem2);
			}
			if (p == 0 && mon[5] == 2) {
				window.draw(shapem2);
			}
		}

		if (dmon[3].deletesp != 1) {
			if (p == 0 && mon[1] == 3) {
				window.draw(shapem3);
			}
			if (p == 0 && mon[2] == 3) {
				window.draw(shapem3);
			}
			if (p == 0 && mon[3] == 3) {
				window.draw(shapem3);
			}
			if (p == 0 && mon[4] == 3) {
				window.draw(shapem3);
			}
			if (p == 0 && mon[5] == 3) {
				window.draw(shapem3);
			}
		}

		if (dmon[4].deletesp != 1) {
			if (p == 0 && mon[1] == 4) {
				window.draw(shapem4);
			}
			if (p == 0 && mon[2] == 4) {
				window.draw(shapem4);
			}
			if (p == 0 && mon[3] == 4) {
				window.draw(shapem4);
			}
			if (p == 0 && mon[4] == 4) {
				window.draw(shapem4);
			}
			if (p == 0 && mon[5] == 4) {
				window.draw(shapem4);
			}
		}

		if (dmon[5].deletesp != 1) {
			if (p == 0 && mon[1] == 5) {
				window.draw(shapem5);
			}
			if (p == 0 && mon[2] == 5) {
				window.draw(shapem5);
			}
			if (p == 0 && mon[3] == 5) {
				window.draw(shapem5);
			}
			if (p == 0 && mon[4] == 5) {
				window.draw(shapem5);
			}
			if (p == 0 && mon[5] == 5) {
				window.draw(shapem5);
			}
		}

		if (dmon[6].deletesp != 1) {
			if (p == 0 && mon[1] == 6) {
				window.draw(shapem6);
			}
			if (p == 0 && mon[2] == 6) {
				window.draw(shapem6);
			}
			if (p == 0 && mon[3] == 6) {
				window.draw(shapem6);
			}
			if (p == 0 && mon[4] == 6) {
				window.draw(shapem6);
			}
			if (p == 0 && mon[5] == 6) {
				window.draw(shapem6);
			}
		}

		if (dmon[7].deletesp != 1) {
			if (p == 0 && mon[1] == 7) {
				window.draw(shapem7);
			}
			if (p == 0 && mon[2] == 7) {
				window.draw(shapem7);
			}
			if (p == 0 && mon[3] == 7) {
				window.draw(shapem7);
			}
			if (p == 0 && mon[4] == 7) {
				window.draw(shapem7);
			}
			if (p == 0 && mon[5] == 7) {
				window.draw(shapem7);
			}
		}


		if (dmon[8].deletesp != 1) {
			if (p == 0 && mon[1] == 8) {
				window.draw(shapem8);
			}
			if (p == 0 && mon[2] == 8) {
				window.draw(shapem8);
			}
			if (p == 0 && mon[3] == 8) {
				window.draw(shapem8);
			}
			if (p == 0 && mon[4] == 8) {
				window.draw(shapem8);
			}
			if (p == 0 && mon[5] == 8) {
				window.draw(shapem8);
			}
		}

		if (dmon[9].deletesp != 1) {
			if (p == 0 && mon[1] == 9) {
				window.draw(shapem9);
			}
			if (p == 0 && mon[2] == 9) {
				window.draw(shapem9);
			}
			if (p == 0 && mon[3] == 9) {
				window.draw(shapem9);
			}
			if (p == 0 && mon[4] == 9) {
				window.draw(shapem9);
			}
			if (p == 0 && mon[5] == 9) {
				window.draw(shapem9);
			}
		}

		if (dmon[10].deletesp != 1) {
			if (p == 0 && mon[1] == 10) {
				window.draw(shapem10);
			}
			if (p == 0 && mon[2] == 10) {
				window.draw(shapem10);
			}
			if (p == 0 && mon[3] == 10) {
				window.draw(shapem10);
			}
			if (p == 0 && mon[4] == 10) {
				window.draw(shapem10);
			}
			if (p == 0 && mon[5] == 10) {
				window.draw(shapem10);
			}
		}

		if (dmon[11].deletesp != 1) {
			if (p == 0 && mon[1] == 11) {
				window.draw(shapem11);
			}
			if (p == 0 && mon[2] == 11) {
				window.draw(shapem11);
			}
			if (p == 0 && mon[3] == 11) {
				window.draw(shapem11);
			}
			if (p == 0 && mon[4] == 11) {
				window.draw(shapem11);
			}
			if (p == 0 && mon[5] == 11) {
				window.draw(shapem11);
			}
		}

		if (dmon[12].deletesp != 1) {
			if (p == 0 && mon[1] == 12) {
				window.draw(shapem12);
			}
			if (p == 0 && mon[2] == 12) {
				window.draw(shapem12);
			}
			if (p == 0 && mon[3] == 12) {
				window.draw(shapem12);
			}
			if (p == 0 && mon[4] == 12) {
				window.draw(shapem12);
			}
			if (p == 0 && mon[5] == 12) {
				window.draw(shapem12);
			}
		}

		if (dmon[13].deletesp != 1) {
			if (p == 0 && mon[1] == 13) {
				window.draw(shapem13);
			}
			if (p == 0 && mon[2] == 13) {
				window.draw(shapem13);
			}
			if (p == 0 && mon[3] == 13) {
				window.draw(shapem13);
			}
			if (p == 0 && mon[4] == 13) {
				window.draw(shapem13);
			}
			if (p == 0 && mon[5] == 13) {
				window.draw(shapem13);
			}
		}


		if (dmon[14].deletesp != 1) {
			if (p == 0 && mon[1] == 14) {
				window.draw(shapem14);
			}
			if (p == 0 && mon[2] == 14) {
				window.draw(shapem14);
			}
			if (p == 0 && mon[3] == 14) {
				window.draw(shapem14);
			}
			if (p == 0 && mon[4] == 14) {
				window.draw(shapem14);
			}
			if (p == 0 && mon[5] == 14) {
				window.draw(shapem14);
			}
		}

		if (dmon[15].deletesp != 1) {
			if (p == 0 && mon[1] == 15) {
				window.draw(shapem15);
			}
			if (p == 0 && mon[2] == 15) {
				window.draw(shapem15);
			}
			if (p == 0 && mon[3] == 15) {
				window.draw(shapem15);
			}
			if (p == 0 && mon[4] == 15) {
				window.draw(shapem15);
			}
			if (p == 0 && mon[5] == 15) {
				window.draw(shapem15);
			}
		}


		if (dmon[16].deletesp != 1) {
			if (p == 0 && mon[1] == 16) {
				window.draw(shapem16);
			}
			if (p == 0 && mon[2] == 16) {
				window.draw(shapem16);
			}
			if (p == 0 && mon[3] == 16) {
				window.draw(shapem16);
			}
			if (p == 0 && mon[4] == 16) {
				window.draw(shapem16);
			}
			if (p == 0 && mon[5] == 16) {
				window.draw(shapem16);
			}
		}

		if (dmon[17].deletesp != 1) {
			if (p == 0 && mon[1] == 17) {
				window.draw(shapem17);
			}
			if (p == 0 && mon[2] == 17) {
				window.draw(shapem17);
			}
			if (p == 0 && mon[3] == 17) {
				window.draw(shapem17);
			}
			if (p == 0 && mon[4] == 17) {
				window.draw(shapem17);
			}
			if (p == 0 && mon[5] == 17) {
				window.draw(shapem17);
			}
		}


		if (dmon[18].deletesp != 1) {
			if (p == 0 && mon[1] == 18) {
				window.draw(shapem18);
			}
			if (p == 0 && mon[2] == 18) {
				window.draw(shapem18);
			}
			if (p == 0 && mon[3] == 18) {
				window.draw(shapem18);
			}
			if (p == 0 && mon[4] == 18) {
				window.draw(shapem18);
			}
			if (p == 0 && mon[5] == 18) {
				window.draw(shapem18);
			}
		}

		if (dmon[19].deletesp != 1) {
			if (p == 0 && mon[1] == 19) {
				window.draw(shapem19);
			}
			if (p == 0 && mon[2] == 19) {
				window.draw(shapem19);
			}
			if (p == 0 && mon[3] == 19) {
				window.draw(shapem19);
			}
			if (p == 0 && mon[4] == 19) {
				window.draw(shapem19);
			}
			if (p == 0 && mon[5] == 19) {
				window.draw(shapem19);
			}
		}


		if (dmon[20].deletesp != 1) {
			if (p == 0 && mon[1] == 20) {
				window.draw(shapem20);
			}
			if (p == 0 && mon[2] == 20) {
				window.draw(shapem20);
			}
			if (p == 0 && mon[3] == 20) {
				window.draw(shapem20);
			}
			if (p == 0 && mon[4] == 20) {
				window.draw(shapem20);
			}
			if (p == 0 && mon[5] == 20) {
				window.draw(shapem20);
			}
		}

		if (dmon[21].deletesp != 1) {
			if (p == 0 && mon[1] == 21) {
				window.draw(shapem21);
			}
			if (p == 0 && mon[2] == 21) {
				window.draw(shapem21);
			}
			if (p == 0 && mon[3] == 21) {
				window.draw(shapem21);
			}
			if (p == 0 && mon[4] == 21) {
				window.draw(shapem21);
			}
			if (p == 0 && mon[5] == 21) {
				window.draw(shapem21);
			}
		}

		if (dmon[22].deletesp != 1) {
			if (p == 0 && mon[1] == 22) {
				window.draw(shapem22);
			}
			if (p == 0 && mon[2] == 22) {
				window.draw(shapem22);
			}
			if (p == 0 && mon[3] == 22) {
				window.draw(shapem22);
			}
			if (p == 0 && mon[4] == 22) {
				window.draw(shapem22);
			}
			if (p == 0 && mon[5] == 22) {
				window.draw(shapem22);
			}
		}

		if (dmon[23].deletesp != 1) {
			if (p == 0 && mon[1] == 23) {
				window.draw(shapem23);
			}
			if (p == 0 && mon[2] == 23) {
				window.draw(shapem23);
			}
			if (p == 0 && mon[3] == 23) {
				window.draw(shapem23);
			}
			if (p == 0 && mon[4] == 23) {
				window.draw(shapem23);
			}
			if (p == 0 && mon[5] == 23) {
				window.draw(shapem23);
			}
		}

		if (dmon[24].deletesp != 1) {
			if (p == 0 && mon[1] == 24) {
				window.draw(shapem24);
			}
			if (p == 0 && mon[2] == 24) {
				window.draw(shapem24);
			}
			if (p == 0 && mon[3] == 24) {
				window.draw(shapem24);
			}
			if (p == 0 && mon[4] == 24) {
				window.draw(shapem24);
			}
			if (p == 0 && mon[5] == 24) {
				window.draw(shapem24);
			}
		}


		if (dmon[25].deletesp != 1) {
			if (p == 0 && mon[1] == 25) {
				window.draw(shapem25);
			}
			if (p == 0 && mon[2] == 25) {
				window.draw(shapem25);
			}
			if (p == 0 && mon[3] == 25) {
				window.draw(shapem25);
			}
			if (p == 0 && mon[4] == 25) {
				window.draw(shapem25);
			}
			if (p == 0 && mon[5] == 25) {
				window.draw(shapem25);
			}
		}


		if (dmon[26].deletesp != 1) {
			if (p == 0 && mon[1] == 26) {
				window.draw(shapem26);
			}
			if (p == 0 && mon[2] == 26) {
				window.draw(shapem26);
			}
			if (p == 0 && mon[3] == 26) {
				window.draw(shapem26);
			}
			if (p == 0 && mon[4] == 26) {
				window.draw(shapem26);
			}
			if (p == 0 && mon[5] == 26) {
				window.draw(shapem26);
			}
		}

		if (p == 4 && cheak == 1) {
			window.draw(howto1);


		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (p == 4 && cheak == 1) {
				rs = 0;
				p = 0;
				num = 0;
				cheak = 3;
				window.draw(bg);
				window.draw(shapeSprite);
				window.draw(score);
				window.draw(score1);
				window.draw(scoreCurrent);
				window.draw(collision);
				window.draw(line);
				window.setView(view);
				for (s = 0; s <= 1; s++)
				{
					mons1();
					break;
				}
				printf("%d", rs);
				Sleep(300);

			}
			else {
				p = 4;
				printf("%d", p);
				Sleep(300);

			}
		}*/

		window.display();

		int xOp = rand() % 30;
		int yOp = rand() % 1500;


		std::stringstream scoreShow;
		scoreShow << currentScore;
		scoreCurrent.setString(scoreShow.str().c_str());



		if (shapeSprite.getPosition().x < 10000 && p == 0) {
			shapeSprite.move(speed * deltaTime, 0.f * speed);
			//line.move(speed *deltaTime, 0.f * speed);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, 110, 91));




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
			//line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0 && dmon[1].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\na");
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem2.getGlobalBounds())) {
			//line.setPosition(sf::Vector2f(xOp, yOp));
			if (p == 0 && dmon[2].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nb");
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem3.getGlobalBounds())) {

			if (p == 0 && dmon[3].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nc");
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem4.getGlobalBounds())) {

			if (p == 0 && dmon[4].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nd");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem5.getGlobalBounds())) {

			if (p == 0 && dmon[5].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\ne");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem6.getGlobalBounds())) {

			if (p == 0 && dmon[6].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nf");
				sound.stop();
				sound1.play();
			}
		}

		if (line.getGlobalBounds().intersects(shapem7.getGlobalBounds())) {

			if (p == 0 && dmon[7].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\ng");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem8.getGlobalBounds())) {

			if (p == 0 && dmon[8].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nh");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem9.getGlobalBounds())) {

			if (p == 0 && dmon[9].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\ni");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem10.getGlobalBounds())) {

			if (p == 0 && dmon[10].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nj");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem11.getGlobalBounds())) {

			if (p == 0 && dmon[11].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nk");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem12.getGlobalBounds())) {

			if (p == 0 && dmon[12].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nl");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem13.getGlobalBounds())) {

			if (p == 0 && dmon[13].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nm");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem14.getGlobalBounds())) {

			if (p == 0 && dmon[14].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nn");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem15.getGlobalBounds())) {

			if (p == 0 && dmon[15].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\no");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem16.getGlobalBounds())) {

			if (p == 0 && dmon[16].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\np");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem17.getGlobalBounds())) {

			if (p == 0 && dmon[17].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nq");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem18.getGlobalBounds())) {

			if (p == 0 && dmon[18].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nr");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem19.getGlobalBounds())) {

			if (p == 0 && dmon[19].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\ns");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem20.getGlobalBounds())) {

			if (p == 0 && dmon[20].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nt");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem21.getGlobalBounds())) {

			if (p == 0 && dmon[21].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nu");
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem22.getGlobalBounds())) {

			if (p == 0 && dmon[22].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nv");
				sound.stop();
				sound1.play();
			}


		}

		if (line.getGlobalBounds().intersects(shapem23.getGlobalBounds())) {

			if (p == 0 && dmon[23].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nw");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem24.getGlobalBounds())) {

			if (p == 0 && dmon[24].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nx");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem25.getGlobalBounds())) {

			if (p == 0 && dmon[25].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\ny");
				sound.stop();
				sound1.play();
			}


		}
		if (line.getGlobalBounds().intersects(shapem26.getGlobalBounds())) {

			if (p == 0 && dmon[26].deletesp != 1) {
				p = 2;
				cheak = 2;

				printf("%d", p);
				printf("\nz");
				sound.stop();
				sound1.play();
			}


		}

		if (it1.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			//it1.setPosition(sf::Vector2f(xOp, yOp));
			currentScore += 200;
			sound2.play();

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