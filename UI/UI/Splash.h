#ifndef SPLASH
#define SPLASH
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#include<SFML\Graphics.hpp>
#include"Game.h"

class Game;

//splash screen
class Splash {

public:
	Splash(Game & game, sf::Font font);
	~Splash();


	void update(sf::Time deltaTime); //update
	void render(sf::RenderWindow &window); //render
	void wiper(sf::Time deltaTime); //the wiper
	int textureWidth = 800; //texture width
private:
	Game *m_game;
	sf::Time m_cumulativeTime;
	sf::Font m_comicSans; //font
	sf::Text m_textMessage;

	sf::Vector2f m_textPos; 

	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Texture m_background;
	sf::Sprite m_spriteBackground; //background


	sf::Texture m_ChalkyT;
	sf::Sprite m_ChalkS; //wiper 

	float m_Cscale;
	float m_scale;
	float m_rotation;


	bool toWipe = false;
};



#endif // !SPLASH