#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "MenuObject.h"

using namespace std;

class MenuPage
{	
public:	
/*	
	struct MenuObject
	{
		int action;		
		
		sf::Vector2f Pos; // Position
		sf::Rect<int> *rect; // x1,y1,x2,y2 
		sf::Sprite sprite;
		sf::String text;
		
		enum State{Normal, Focused} _state;
		void SetPosition(float x,float y){Pos.x=x;Pos.y=y;}
		void CreateRect(float x,float y){rect = new sf::Rect<int>(Pos.x,Pos.y,Pos.x+x,Pos.y+y);}
		virtual void OnFocused();
	};
*/	
	
	void Draw();
	virtual int Show();
	virtual int GetMenuReponse();
	virtual int HandleClick(int x, int y);
	virtual void HandleMouseOver(int x, int y);

	list<MenuObject> _objects;
	sf::RenderWindow *window;	
	
};

#endif // MENUPAGE_H