#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(sf::RenderWindow& window)
{
	//connect renderwindows
	this->window = &window;
	
	int buttonWidth = 200;
	int buttonHeight = 40;
	sf::String text;
	sf::Sprite sprite;
	
	//Setup buttons
	MenuObject backButton;
	MenuObject FSButton; // FullScreen
	MenuObject ResButton; // Resolution
	MenuObject VsyncButton; // VerticalSync
	MenuObject AA; // Antialiasing Level
	
	// BACK BUTTON
	backButton.SetPosition(100,40);
	backButton.CreateRect(buttonWidth ,buttonHeight);
	backButton.action = Back;	
	text.SetText("Back");
	text.SetPosition(backButton.pos);
	text.SetColor(sf::Color::Red);
	backButton.Text.push_back(text);
	text.SetColor(sf::Color::Green);
	backButton.Text.push_back(text);

	// load images
	//replace this with a function?
	sf::Image image;
	if(image.LoadFromFile("test.png") != true);
	sf::Sprite _backSprite(image);	
	_backSprite.SetPosition(backButton.rect->Left,backButton.rect->Top);
	_backSprite.Resize(backButton.rect->GetWidth(),backButton.rect->GetHeight());
	//setup sprites
	backButton.Sprites.push_back(_backSprite);
	
	
	// FULLSCREEN BUTTON
	FSButton.SetPosition(180,100);
	FSButton.CreateRect(buttonWidth ,buttonHeight);
	FSButton.action = FullScreen;


	// Add to list
	_objects.push_back(backButton);
	_objects.push_back(FSButton);

}
