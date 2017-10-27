#include "License.h"
#include <iostream>
#include "Game.h"
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

// This is where I set the font, messsage and output it to the screen  
License::License(Game & game, sf::Font font) :
	m_game(&game), m_comicSans(font), m_textMessage2("J Studios Present", m_comicSans, 30)
{

	m_textMessage2.setPosition(300, 250.0f);
	m_textMessage2.setFillColor(sf::Color::White);

	if (!m_texture.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	m_colour = sf::Color(0, 0, 0, alpha);
}


License::~License()

{
	std::cout << "destructing Splash" << std::endl;
}


//alpha of the text is adjusted here for 5 seconds
void License::update(sf::Time deltaTime)

{
	m_cumulatuiveTime += deltaTime;

	//decrease the alpha
	if (alpha > 0)
	{
		alpha--;
	}

	m_colour = sf::Color(255, 255, 255, alpha);
	m_textMessage2.setFillColor(m_colour);

	
	//go to splash after 5 seconds
	if (m_cumulatuiveTime.asSeconds() > 5)
	{


		m_game->setGameState(GameState::TheSplash);


	}

}


//render the sprites and the text
void License::render(sf::RenderWindow & window)
{

	// I set the colour and message 
	window.clear(sf::Color::Black);
	window.draw(m_sprite);
	window.draw(m_textMessage2);
	window.display();
}