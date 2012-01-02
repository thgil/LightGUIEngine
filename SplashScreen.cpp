#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	sf::Image image;
	sf::Color bgColor = sf::Color(40,40,40);
	
	//Replace this?
	if (image.LoadFromFile("test.png") != true)
		return;
	
	sf::Sprite sprite(image);
	cerr<<renderWindow.GetWidth()/2<<" "<< renderWindow.GetHeight()/2<<endl;
	sprite.SetCenter(184/2,184/2);
	sprite.SetPosition(renderWindow.GetWidth()/2 , renderWindow.GetHeight()/2);
	
	renderWindow.Clear(bgColor);
	renderWindow.Draw(sprite);
	renderWindow.Display();
	
	sf::Event event;
	sf::Clock clock;
	
	while(clock.GetElapsedTime()<3)
	{
		while(renderWindow.GetEvent(event))
		{
			if (   event.Type == sf::Event::KeyPressed 
				|| event.Type == sf::Event::MouseButtonPressed
				|| event.Type == sf::Event::Closed) 
			{
				renderWindow.Clear(bgColor);
				return;
			}
		}
	}
	renderWindow.Clear(bgColor);
	return;
}