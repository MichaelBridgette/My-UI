#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#ifndef LICENSE
#define LICENSE
#include "Game.h"

class Game;

//license screen
class License
{

public:


	License(Game& game, sf::Font font);
	~License();

	void update(sf::Time deltaTime); //update
	void render(sf::RenderWindow& window); //draw

private:
	Game *m_game;
	sf::Time m_cumulatuiveTime; //time
	sf::Font m_comicSans; //font 
	sf::Text m_textMessage2; //the text
	sf::Texture m_texture; // texture
	sf::Sprite m_sprite; //sprite for the texture
	sf::Color m_colour; //color
	float alpha = 255.0f; //alpha level
};

#endif // !SPLASH



