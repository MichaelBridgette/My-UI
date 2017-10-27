#pragma once
#ifndef OPTIONS
#define OPTIONS

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Label.h"
#include"RadioButton.h"
#include"XBOX360CONTROLLER.h"
#include"Widget.h"
#include"Slider.h"
#include "GUI.h"
#include"Game.h"
#define MAX_ITEMS 4  //the amount of menu options
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/

class Game;

//options menu of the game
class Options {

public:
	Options(float width, float height, Game& game);
	//~Options();
	void draw(sf::RenderWindow &window); //draw
	void update(); //update
	void setEasy(); //set easy diff
	void setMedium(); //set medium diff
	void setHard(); //set hard diff

	void increaseVolumeMusic(); //increase volume of music
	void decreaseVolumeMusic(); //decrease it

	
private:
	int m_selectedItemIndex; //current indexed item

	Label m_label;
	Label *m_icon[2]; //label

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Widget *m_widget[MAX_ITEMS]; //ui elements

	Xbox360Controller m_xbox; //xbox controller
	bool m_itemSelected;
	GUI m_gui; //gui
	
	float volumeMusic; //volume of music
	Game *m_game;


};
#endif // !OPTIONS