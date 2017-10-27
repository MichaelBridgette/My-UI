#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#include<SFML\Graphics.hpp>
#include"Widget.h"

class Label: public Widget {
public:
	Label(std::string s ,float x, float y);
	Label(std::string s, float x, float y, std::string textureName); //constructors
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop
	void setUnderLined(); //make  label underlined
	void updateText(std::string s); //change the text of the label
	void changeTextSize(int size); //change size of the label
protected:
	sf::Vector2f m_pos;
	sf::Text m_text;
	sf::Font m_font;
	

	//icon stuff that probably wont be used for most labels
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	bool hasTexture;
	int textSize;


};
