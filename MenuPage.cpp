#include "MenuPage.h"

void MenuPage::Draw()
{
	window->Clear(sf::Color(40,40,40));
	list<MenuObject>::iterator it;
	for( it=_objects.begin(); it!=_objects.end(); it++)
	{
		window->Draw((*it).sprite);	
		window->Draw((*it).text);
	}
	window->Display();
}

int MenuPage::Show()
{
	
	Draw();

	return GetMenuReponse();
}

int MenuPage::GetMenuReponse()
{
	sf::Event menuEvent;
	
	while(true)
	{
		while(window->GetEvent(menuEvent))
		{
			// update()?
			//
			// Mouseover? like
			// if( mouse moved )
			//		return 
			
			if(menuEvent.Type == sf::Event::MouseMoved)
				HandleMouseOver(menuEvent.MouseMove.X,menuEvent.MouseMove.Y);
			
			if(menuEvent.Type == sf::Event::MouseButtonPressed)
				return HandleClick(menuEvent.MouseButton.X,menuEvent.MouseButton.Y);
			
			if(menuEvent.Type == sf::Event::Closed)
				return 1; // Exit state?
		}
	}
}

int MenuPage::HandleClick(int x, int y)
{
	list<MenuObject>::iterator it;
	sf::Rect<int>* menuItemRect;
	
	for( it=_objects.begin(); it!=_objects.end(); it++)
	{
		menuItemRect = (*it).rect;
		if( menuItemRect->Bottom > y 
		   && menuItemRect->Top < y 
		   && menuItemRect->Left < x 
		   && menuItemRect->Right > x)
		{
			cerr<<"returning action" <<endl;
			return (*it).action;
		}
		
	}
	delete menuItemRect;
	return 0;
}

void MenuPage::HandleMouseOver(int x, int y)
{		
	list<MenuObject>::iterator it;
	
	for( it=_objects.begin(); it!=_objects.end(); it++)
	{
		if( (*it).rect->Bottom > y 
		   && (*it).rect->Top < y 
		   && (*it).rect->Left < x 
		   && (*it).rect->Right > x)
		{
			(*it)._state = MenuObject::Focused;
/*	TBR
			(*it).text.SetColor(sf::Color::Green);
			window->Draw((*it).text);
			window->Display();
*/
			//Draw();
		}
		else (*it)._state = MenuObject::Normal;
		
	}
}