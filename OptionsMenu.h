#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "MenuPage.h"

using namespace std;

class OptionsMenu: public MenuPage
{
public:
	enum OptionsMenuResult{Nothing,Back,FullScreen,Resolution,Vsync,AA};
	
	OptionsMenu(sf::RenderWindow& window);
};

#endif // OPTIONSMENU_H