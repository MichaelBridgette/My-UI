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

//sliders
class Slider: public Widget {

public:
	Slider(float x, float y, float &value, std::string s);

	void getFocus() override; //gain highlight
	void loseFocus() override; //lose highlight
	bool checkFocus()override; //check for focus

	void update()override; //update
	void draw(sf::RenderWindow &window)override; //draw
	int getValue(); //get sliders value
	void increaseValue(); //increase rect length
	void decreaseValue(); //decrease it

private:
	
	sf::RectangleShape m_innerRect; //inner rectangle

	float m_rectX = 180; 
	float m_rectY = 10; 
	float m_val; //slider value

	sf::Font m_font;
	sf::Text m_text;

};