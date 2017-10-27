#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#include<SFML\Graphics.hpp>
#include"Label.h"
#include"Widget.h"
#include<functional>

class Button:  public Widget       //button ui element
{
public:
	Button(std::string s, float x, float y); //constructor
	Button(std::string s, float x, float y, sf::Color color, std::string tag); //overloaded
	~Button();
	 void getFocus() override; //make button the current highlighted element
	 void loseFocus()override; //lose highlight
	 bool checkFocus()override;   //check if highlighed
	 void update()override; //update loop
	 void draw(sf::RenderWindow &window)override; //draw loop
	 void setRectColor(sf::Color color); //set the rect color of button
	 void endAnim(); //animation transition
	

protected:
	sf::RectangleShape m_rect; //rectangle that will surround text
	bool m_hasFocus; //simple bool for check
	sf::Font m_font; //font
	sf::Text m_text; //text object
	float posX; //xpos
	float posY;//ypos
	
	
};

