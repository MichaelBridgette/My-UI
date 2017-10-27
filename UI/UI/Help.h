#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#ifndef HELPSCREEN
#define HELPSCREEN
#include"Game.h"
#include"XBOX360CONTROLLER.h"
#include"Label.h"
#include"GUI.h"

class Game;

//simple screen with labels
class HelpScreen {
public:
	HelpScreen(float width, float height, Game& game);
	~HelpScreen();
	void draw(sf::RenderWindow &window);
	void update();

private:
	Game *m_game;
	Xbox360Controller m_xbox;
	Label *m_label; //label
	GUI m_gui; //gui
	sf::Texture m_texture;
	sf::Sprite m_sprite; //background
};

#endif // !HELPSCREEN