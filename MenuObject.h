#ifndef MENUOBJECT_H
#define MENUOBJECT_H

#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuObject
{
public:
	int action;		
	
	sf::Vector2f Pos; // Position
	sf::Rect<int> *rect; // x1,y1,x2,y2 
	sf::Sprite sprite;
	sf::String text;
	
	enum State{Normal, Focused} _state;
	void SetPosition(float x,float y){Pos.x=x;Pos.y=y;}
	void CreateRect(float x,float y){rect = new sf::Rect<int>(Pos.x,Pos.y,Pos.x+x,Pos.y+y);}
//	virtual void OnFocused();
};

#endif // MENUOBJECT_H