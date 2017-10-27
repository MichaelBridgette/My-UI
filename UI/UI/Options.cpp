#include"Options.h"
#include "Label.h"
#include<iostream>
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//options menu of the game
Options::Options(float width , float height , Game &game) :
	m_label("Options", width / 2, (height / MAX_ITEMS + 2.0f)*0.0f),
	m_game(&game)
	
{
	volumeMusic = 100; //volume
	m_label.setUnderLined();
	m_selectedItemIndex = 0; //start at top
	if (!m_texture.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);
	m_itemSelected = false;

	//ui elements
	m_widget[0] = new RadioButton("Easy", width / 2, (height / MAX_ITEMS + 2.0f)*1.0f, "diff");
	m_widget[0]->getFocus();
	m_widget[0]->getActive();
	m_widget[0]->Enter = std::bind(&Options::setEasy, this);
	m_widget[1] = new RadioButton("Medium", width / 2, (height / MAX_ITEMS + 2.0f)*1.5f, "diff");
	m_widget[1]->Enter = std::bind(&Options::setMedium, this);
	m_widget[2] = new RadioButton("Hard", width / 2, (height / MAX_ITEMS + 2.0f)*2.0f, "diff");
	m_widget[2]->Enter = std::bind(&Options::setHard, this);
	m_gui.addLabel(&m_label);
	m_widget[3] = new Slider(width / 2, (height / MAX_ITEMS + 2.0f)*3.5f, volumeMusic, "Music Volume");
	m_widget[3]->AdjustAdd = std::bind(&Options::increaseVolumeMusic, this);
	m_widget[3]->AdjustMinus = std::bind(&Options::decreaseVolumeMusic, this);
	m_gui.vertical = true; //control scheme

	//put in gui 
	for each (Widget* var in m_widget)
	{
		m_gui.addWidget(var);
	}
	m_gui.addLabel(&m_label);

	//icons
	m_icon[0] = new Label("select", (width / 10), (height*1.5)+100 , "a button.png");
	m_icon[1] = new Label("back", (width / 10) + 100, (height*1.5)+100 , "b button.png");
	for each  (Label* icon in m_icon)
	{
		m_gui.addLabel(icon);
	}
}
//draw all elements of options
void Options::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
	m_gui.draw(window);
}

//update all the elements
void Options::update()
{
	m_gui.update(m_selectedItemIndex, MAX_ITEMS);

	m_xbox.update();

	if (m_xbox.m_currentState.B == true && !m_xbox.m_previousState.B)
	{
		m_game->setGameState(GameState::TheMenu);
	}
}

//set easy difficulty
void Options::setEasy()
{
	//std::cout << "easy" << std::endl;
	m_game->setGameDifficulty(GameDifficulty::Easy);
}

//set medium difficulty
void Options::setMedium()
{
	//std::cout << "medium" << std::endl;
	m_game->setGameDifficulty(GameDifficulty::Medium);
}

//set hard difficulty
void Options::setHard()
{
	//std::cout << "hard" << std::endl;
	m_game->setGameDifficulty(GameDifficulty::Hard);
}

//increase music volume
void Options::increaseVolumeMusic()
{
	//std::cout << m_game->m_music.getVolume() << std::endl;
	if (volumeMusic < 100)
	{
		volumeMusic++;
	}
	m_game->m_music.setVolume(volumeMusic);
}

//decrease music volume
void Options::decreaseVolumeMusic()
{
	//std::cout << m_game->m_music.getVolume() << std::endl;
	if (volumeMusic > 0)
	{
		volumeMusic--;
	}
	m_game->m_music.setVolume(volumeMusic);
}




