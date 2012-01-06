#include "MenuPage.h"

void MenuPage::Draw()
{
	window->Clear(sf::Color(40,40,40));

	for( list<MenuObject>::iterator it=_objects.begin(); it!=_objects.end(); it++)
	{
		(*it).Draw(window);
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
		//cerr<<"Looping in Menu"<<endl;
		Draw();
		while(window->GetEvent(menuEvent))
		{
			
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
	sf::Rect<int>* menuItemRect;
	
	for( list<MenuObject>::iterator it=_objects.begin(); it!=_objects.end(); it++)
	{
		if( (*it).rect->Bottom > y && (*it).rect->Top < y 
		   && (*it).rect->Left < x && (*it).rect->Right > x)
		{
			cerr<<"returning action" <<endl;
			return (*it).OnClick();
		}
		
	}

	return 0;
}

void MenuPage::HandleMouseOver(int x, int y)
{			
	for( list<MenuObject>::iterator it=_objects.begin(); it!=_objects.end(); it++)
	{
		if( (*it).rect->Bottom > y && (*it).rect->Top < y 
		   && (*it).rect->Left < x && (*it).rect->Right > x)
		{
			(*it)._state = MenuObject::Focused;

		}
		else (*it)._state = MenuObject::Normal;
		
	}
}
