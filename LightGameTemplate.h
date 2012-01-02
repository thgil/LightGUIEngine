#ifndef LIGHTGAMETEMPLATE
#define LIGHTGAMETEMPLATE

#include <SFML/Graphics.hpp>
#include <iostream>

#include "MainMenu.h"
#include "SplashScreen.h"

#include "TLines.h"

using namespace std;

class LightGameTemplate
{

public:
	static void Start();
	//const static TLines& GetTLines();
	
private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowSplashScreen();
	static void ShowMainMenu();
	static void ShowOptionsMenu();
	
	enum GameState { 
		Uninit, ShowSplash, Paused,
		ShowMain,
		ShowOptions,
		Playing, Exiting};
	
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;	
	
	static TLines _Lines;

};

#endif // LIGHTGAMETEMPLATE