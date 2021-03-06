#include "LightGameTemplate.h"

TLines LightGameTemplate::_Lines;
LightGameTemplate::GameState LightGameTemplate::_gameState = Uninit;
sf::RenderWindow LightGameTemplate::_mainWindow;

void LightGameTemplate::Start()
{
	std::cerr<<"Game Start called"<<std::endl;
	if(_gameState != LightGameTemplate::Uninit)
		return;
	
	// Move this to somewhere else
	// Or something...
	std::cerr<<"Creating Renderwindow"<<std::endl;
	_mainWindow.Create(sf::VideoMode(1024,768,32),"Holy shit it's LightGameTemplate!");
	
	
	std::cerr<<"Showing Splash"<<std::endl;
	_gameState = LightGameTemplate::ShowSplash;
	
	while(!IsExiting())
	{
		GameLoop();
	}	
	
	_mainWindow.Close();
}

bool LightGameTemplate::IsExiting()
{
	if(_gameState == LightGameTemplate::Exiting)
		return true;
	else 
		return false;
}



/*const TLines& LightGameTemplate::GetTLines()
{
	return _Lines;
}*/



void LightGameTemplate::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.GetEvent(currentEvent);

	static int count=0;
	
	switch (_gameState) {
			
		case LightGameTemplate::ShowMain:
			ShowMainMenu();
			cerr<<"Leaving Main"<<endl;
			break;
			
		case LightGameTemplate::ShowOptions:
			ShowOptionsMenu();
			cerr<<"Leaving Options"<<endl;
			break;	
			
		case LightGameTemplate::ShowSplash:
			ShowSplashScreen();
			cerr<<"Leaving Splash"<<endl;
			break;
			
		case LightGameTemplate::Playing:
		{
			cerr<<"Playing: count:"<<count++<<" kc:"<<currentEvent.Key.Code<<endl;
			
			_mainWindow.Clear(sf::Color(40,40,40));
			
			_Lines.update();
			_Lines.draw(_mainWindow);
			
			//_mainWindow.Clear(sf::Color(0,0,0));
			_mainWindow.Display();
			
			if(currentEvent.Type == sf::Event::Closed)
				_gameState = LightGameTemplate::Exiting;
			
			if(currentEvent.Type == sf::Event::KeyPressed)
			{
				cerr << "Key Pressed"<<endl;
				if(currentEvent.Key.Code == sf::Key::Escape) 
				{
					cerr<<currentEvent.Key.Code<<" == "<<sf::Key::Escape<<endl;
					_gameState = LightGameTemplate::ShowMain;
				}
			}
			cerr<<"Leaving Playing"<<endl;
			break;
		}
	}
}

void LightGameTemplate::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = LightGameTemplate::ShowMain;
}

void LightGameTemplate::ShowMainMenu()
{
	cerr<<"Entering Menu"<<endl;
	
	MainMenu mainMenu(_mainWindow);
	MainMenu::MainMenuResult result = (MainMenu::MainMenuResult)mainMenu.Show();
	
	cerr<<"ResultFromMain:"<<result<<endl;
	
	switch (result) {
		case MainMenu::Exit:
			cerr<<"Exiting from MainMenu"<<endl;
			_gameState = LightGameTemplate::Exiting;
			break;
		case MainMenu::Play:
			cerr<<"Playing from MainMenu"<<endl;
			_gameState = LightGameTemplate::Playing;
			break;
		case MainMenu::Options:
			cerr<<"Options from MainMenu"<<endl;
			_gameState = LightGameTemplate::ShowOptions;
			break;
	}
	return;
}

void LightGameTemplate::ShowOptionsMenu()
{
	cerr<<"Entering OptionsMenu"<<endl;
	
	MainMenu mainMenu(_mainWindow);
	
	MainMenu::MainMenuResult result = (MainMenu::MainMenuResult)mainMenu.Show();
	
	cerr<<"ResultFromOptions:"<<result<<endl;

	switch (result) {
		case MainMenu::Exit:
			cerr<<"Exiting from OptionsMenu"<<endl;
			_gameState = LightGameTemplate::Exiting;
			break;
		case MainMenu::Play:
			cerr<<"Playing from OptionsMenu"<<endl;
			_gameState = LightGameTemplate::Playing;
			break;
		case MainMenu::Options:
			cerr<<"Playing from OptionsMenu"<<endl;
			_gameState = LightGameTemplate::ShowOptions;
			break;
			
	}
	
}
