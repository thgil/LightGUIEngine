#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window)
{
	//connect renderwindows
	this->window = &window;
	
	int buttonWidth = 200;
	int buttonHeight = 40;
	
	//Setup buttons
	MenuObject exitButton;
	MenuObject playButton;
	MenuObject optionButton;
	
	//setup clickable regions
	//NEW YEAR 2012
	exitButton.SetPosition(100,40);
	exitButton.CreateRect(buttonWidth ,buttonHeight);
	exitButton.text.SetText("Exit");
	exitButton.text.SetPosition(exitButton.Pos);
	exitButton.text.SetColor(sf::Color::Red);
	exitButton.action = Exit;
	
	//setup clickable regions
	playButton.SetPosition(100,100);
	playButton.CreateRect(buttonWidth,buttonHeight);
	playButton.text.SetText("Play");
	playButton.text.SetPosition(playButton.Pos);
	playButton.text.SetColor(sf::Color::Red);
	playButton.action = Play;
	
	//setup clickable regions
	optionButton.SetPosition(100,160);
	optionButton.CreateRect(buttonWidth,buttonHeight);
	optionButton.text.SetText("Options");
	optionButton.text.SetPosition(optionButton.Pos);
	optionButton.text.SetColor(sf::Color::Red);
	optionButton.action = Options;
	
	// load images
	//replace this with a function?
	sf::Image image;
	if(image.LoadFromFile("test.png") != true);

	sf::Sprite _exitSprite(image);	
	_exitSprite.SetPosition(exitButton.rect->Left,exitButton.rect->Top);
	_exitSprite.Resize(exitButton.rect->GetWidth(),exitButton.rect->GetHeight());

	sf::Sprite _playSprite(image);
	_playSprite.SetPosition(playButton.rect->Left,playButton.rect->Top);
	_playSprite.Resize(playButton.rect->GetWidth(),playButton.rect->GetHeight());

	sf::Sprite _optionSprite(image);
	_optionSprite.SetPosition(optionButton.rect->Left,optionButton.rect->Top);
	_optionSprite.Resize(optionButton.rect->GetWidth(),optionButton.rect->GetHeight());
	
	//setup sprites
	exitButton.sprite = _exitSprite;
	playButton.sprite = _playSprite;
	optionButton.sprite = _optionSprite;
	
	// Add to list
	_objects.push_back(exitButton);
	_objects.push_back(playButton);
	_objects.push_back(optionButton);
}

MainMenu::~MainMenu()
{
	/*
	if(window != NULL)
		delete window;
	
	for(list<MenuObject>::iterator it=_objects.begin(); it!=_objects.end(); it++)
	{
		if((*it).rect != NULL)
			delete (*it).rect;
	}
*/
}