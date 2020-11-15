#include "Menu.h"
Menu::Menu(float width, float height) {
	if (!font.loadFromFile("pic/score.ttf")) {

	}
		menu[0].setFont(font);
		menu[0].setFillColor(sf::Color::Yellow);
		menu[0].setString("Play");
		menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
		menu[0].setPosition(sf::Vector2f(750, 100));

		menu[1].setFont(font);
		menu[1].setFillColor(sf::Color::White);
		menu[1].setString("How to");
		menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
		menu[1].setPosition(sf::Vector2f(750, 200));

		menu[2].setFont(font);
		menu[2].setFillColor(sf::Color::White);
		menu[2].setString("Exit");
		menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
		menu[2].setPosition(sf::Vector2f(750,300));

}
Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow& window) {
	for (int i = 0; i < Max_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	if (selectedItem - 1 >= 0) {
		menu[selectedItem].setFillColor(sf::Color::White);
			selectedItem--;
			menu[selectedItem].setFillColor(sf::Color::Yellow);
	}
}


void Menu::MoveDown() {
	if (selectedItem + 1 < Max_ITEMS) {
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Yellow);
	}
}