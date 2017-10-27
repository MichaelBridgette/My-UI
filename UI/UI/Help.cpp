#include "Help.h"
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//help screen constructor
HelpScreen::HelpScreen(float width, float height, Game & game):
	m_game(&game)
{
	if (!m_texture.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);

	m_label = new Label("You Will Get No Help", width/2, height);

	m_gui.addLabel(m_label);
	m_gui.vertical = true;
}

HelpScreen::~HelpScreen()
{
}
//draw elements
void HelpScreen::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
	m_gui.draw(window);
}

//update elements
void HelpScreen::update()
{
	m_xbox.update();

	if ( m_xbox.m_currentState.B == true && !m_xbox.m_previousState.B)
	{
		m_game->setGameState(GameState::TheMenu); //go back to menu
	}
}
