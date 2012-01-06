
#include "MenuObject.h"

void MenuObject::SetPosition(float x,float y)
{
	Pos.x=x;
	Pos.y=y;
}

void MenuObject::CreateRect(float x,float y)
{
	rect = new sf::Rect<int>(Pos.x, Pos.y, Pos.x+x, Pos.y+y );
}

void MenuObject::CreateRect(float x,float y, float x2,float y2)
{
	rect = new sf::Rect<int>(x, y, x2, y2 );
}

void MenuObject::OnFocus()
{
	// do stuff
	// make texts/sprites into a vector/list

}

int MenuObject::OnClick()
{
	// do stuff
	// make texts/sprites into a vector/list
	return action;
}

void MenuObject::Draw(sf::RenderWindow* window)
{
	switch (_state) {
		case Normal:
			if(Sprites.size()>0)window->Draw(Sprites.at(Normal));
			if(Text.   size()>0)window->Draw(Text.   at(Normal));
			break;
		case Focused:
			if(Sprites.size()>1)window->Draw(Sprites.at(Focused));
			if(Text.   size()>1)window->Draw(Text.   at(Focused));
			break;
		case Clicked:
			if(Sprites.size()>2)window->Draw(Sprites.at(Clicked));
			if(Text.   size()>2)window->Draw(Text.   at(Clicked));
			break;	
		default:
			break;
	}
}