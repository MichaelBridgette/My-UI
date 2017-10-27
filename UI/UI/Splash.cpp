#include"Splash.h"
#include<iostream>
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//the splashscreen
Splash::Splash(Game & game, sf::Font font) :
	m_game(&game),
	m_comicSans(font),
	m_textMessage("Press Start", m_comicSans, 30)
{
	m_textPos.x = 300.0f;
	m_textPos.y = 500.0f;
	m_textMessage.setPosition(m_textPos);
	m_textMessage.setFillColor(sf::Color::Yellow);

	if (!m_texture.loadFromFile("TheCrew.png"))
	{
		//handle error
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	m_scale = 1.35f;
	m_sprite.setScale(1,1);
	m_rotation = 1;
	if (!m_background.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_spriteBackground.setTexture(m_background);
	m_spriteBackground.setPosition(0, 0);
	m_sprite.scale(m_scale, 1.35f);


	if (!m_ChalkyT.loadFromFile("Chalkboard-Eraser.png"))
	{

		//handle

	}
	m_ChalkS.setTexture(m_ChalkyT);
	
	m_ChalkS.setPosition(1200, -50);
	m_ChalkS.rotate(95);
	m_Cscale = 2.5;
	m_ChalkS.setScale(m_Cscale, m_Cscale);
	
};

Splash::~Splash()
{
	std::cout << "Destructing splash" << std::endl;
}

//update the wiper
void Splash::update(sf::Time deltaTime)
{
	if (toWipe)
	{
		wiper(deltaTime);
	}

}

//render all the components of splash screen
void Splash::render(sf::RenderWindow &window)
{
	window.clear(sf::Color::Black);
	window.draw(m_spriteBackground);
	window.draw(m_sprite);

	window.draw(m_ChalkS);
	window.draw(m_textMessage);
	window.display();
}

//wiper moves across the screen
void Splash::wiper(sf::Time deltaTime)
{
	toWipe = true;

	m_cumulativeTime += deltaTime;
	m_sprite.setScale(m_scale, 1.35f);
	float newposX = m_ChalkS.getPosition().x - 8.0f;
	float newposY = m_ChalkS.getPosition().y;
	textureWidth = newposX / 2;
	m_ChalkS.setPosition(newposX, newposY);
	if (newposX > 0)
		m_sprite.setTextureRect(sf::IntRect(0, 0, textureWidth, 600));

	//m_rotation -= 1;
	m_sprite.setRotation(m_rotation);

	if (newposX <= -75)
	{
		toWipe = false;
		//go to menu
		m_game->setGameState(GameState::TheMenu);
	}
}