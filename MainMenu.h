#ifndef MAINMENU_H
#define MAINMENU_H

#include "MenuPage.h"

using namespace std;

class MainMenu: public MenuPage
{
public:
	enum MainMenuResult{Nothing,Exit,Play,Options};
	
	MainMenu(sf::RenderWindow& window);
};

#endif // MAINMENU_H