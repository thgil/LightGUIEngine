#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window)
{
	//connect renderwindows
	this->window = &window;
	
	int buttonWidth = 200;
	int buttonHeight = 40;
	sf::String text;
	sf::Sprite sprite;
	
	
	//Setup buttons
	MenuObject exitButton;
	MenuObject playButton;
	MenuObject optionButton;
	

	//NEW YEAR 2012
// EXIT BUTTON
	exitButton.SetPosition(100,40);
	exitButton.CreateRect(buttonWidth ,buttonHeight);
	exitButton.action = Exit;	
	text.SetText("Exit");
	text.SetPosition(exitButton.pos);
	text.SetColor(sf::Color::Red);
	exitButton.Text.push_back(text);
	text.SetColor(sf::Color::Green);
	exitButton.Text.push_back(text);

// PLAY BUTTON
	playButton.SetPosition(100,100);
	playButton.CreateRect(buttonWidth,buttonHeight);
	playButton.action = Play;	
	text.SetText("Play");
	text.SetPosition(playButton.pos);
	text.SetColor(sf::Color::Red);
	playButton.Text.push_back(text);
	text.SetColor(sf::Color::Blue);
	playButton.Text.push_back(text);

	
// OPTIONS BUTTON
	optionButton.SetPosition(100,160);
	optionButton.CreateRect(buttonWidth,buttonHeight);
	optionButton.action = Options;
	text.SetText("Options");
	text.SetPosition(optionButton.pos);
	text.SetColor(sf::Color::Red);
	optionButton.Text.push_back(text);
	text.SetColor(sf::Color::Yellow);
	optionButton.Text.push_back(text);

	
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
	exitButton.Sprites.push_back(_exitSprite);
	playButton.Sprites.push_back(_playSprite);
	optionButton.Sprites.push_back(_optionSprite);
	
	// Add to list
	_objects.push_back(exitButton);
	_objects.push_back(playButton);
	_objects.push_back(optionButton);
}
