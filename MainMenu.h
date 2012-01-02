#ifndef MAINMENU_H
#define MAINMENU_H

#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuPage.h"

using namespace std;

class MainMenu: public MenuPage
{
public:
	enum MainMenuResult{Nothing,Exit,Play,Options};
	
	MainMenu(sf::RenderWindow& window);
	~MainMenu();
};

#endif // MAINMENU_H