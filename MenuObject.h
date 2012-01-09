#ifndef MENUOBJECT_H
#define MENUOBJECT_H


#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuObject
{
public:
	int action;		
	
	sf::Vector2f pos; // Position of MenuObject
	sf::Rect<int> *rect; // x1,y1,x2,y2 Clickable area
	std::vector<sf::Sprite> Sprites;
	std::vector<sf::String> Text;
	//sf::Sprite sprite; // Images 
	//sf::String text; // Texts
	enum State{Normal, Focused, Clicked} _state; // States 
	
	MenuObject(){_state=Normal;};
	
	void SetPosition(float x,float y);
	void CreateRect(float x,float y);
	void CreateRect(float x,float y, float x2, float y2);	
	
	virtual void OnFocus();
	int OnClick();

	void Draw(sf::RenderWindow* window);

};

template <class T> void Copy(T first,const T second);


#endif // MENUOBJECT_H