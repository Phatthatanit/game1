#pragma once
#include <SFML/Graphics.hpp>
#define Max_ITEMS 3
class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem;  }
private:
	int selectedItem=0;
	sf::Font font;
	sf::Text menu[Max_ITEMS];
};

