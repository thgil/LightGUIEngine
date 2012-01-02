#include <list>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class TLines
{	
private:
	list<sf::Shape> _lines;
	
public:
	void update()
	{
		sf::Randomizer rnum;
	
		sf::Color rcolor = sf::Color(rnum.Random(0,255),rnum.Random(0,255),rnum.Random(0,255));
		
		int P1X = rnum.Random(300,600);
		int P1Y = rnum.Random(300,600);
		int P2X = rnum.Random(300,600);
		int P2Y = rnum.Random(300,600);
		float thickness = rnum.Random(1.f,5.f);
		
		
		sf::Shape line = sf::Shape::Line( P1X, P1Y, P2X, P2Y,thickness, rcolor, 0.f, rcolor);
		
		_lines.push_back(line);
	}
	
	void draw(sf::RenderWindow& window)
	{
		list<sf::Shape>::iterator it;
		
		for( it=_lines.begin(); it!=_lines.end(); it++)
		{
			window.Draw((*it));		
		}
	}
};