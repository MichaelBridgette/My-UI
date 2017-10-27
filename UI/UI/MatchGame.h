#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#ifndef MATCHGAME
#define MATCHGAME

#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Label.h"
#include"XBOX360CONTROLLER.h"
#include "GUI.h"
#include<iostream>
#include"Game.h"
#include<cstdlib>

#define MAX_ITEMS 4  //the amount of menu options
	
class Game;
enum GameDifficulty;
class GUI;
class MatchGame
{
public:
	MatchGame(float width, float height, Game& game, sf::RenderWindow &window, GameDifficulty difficulty); //constructor
	~MatchGame();
	void initialise(GameDifficulty difficulty); //initialise all the game variables, designed mainly with difficulty var in mind
	void draw(); //draw
	void update(); //update

	void reveal(); //reveal highlighted button
	void hide(); //hide the button
	void checkMatch(); //check if button matches label
	void updateTag(); // update labels text
private:
	int m_selectedItemIndex; //the current item/ menu option
	std::vector<Widget*> m_widgets; //ui elements
	std::vector<std::string>m_tags; //container of strings with the required words in the game
	int tagsIndex; //for stepping through m_tags
	Label * m_label;
	Label * m_label2;
	Label *m_icon[4]; //labels/icons
	sf::Texture m_texture;
	sf::Sprite m_sprite; //background
	Xbox360Controller m_xbox; //xbox controller
	GUI m_gui; //gui
	Game *m_game; 
	sf::RenderWindow &m_window;
	sf::Clock m_timer; 
	float m_width;
	float m_height;
	std::string wantedTag; //the word that is required for match

	int revealCounter; //the amount of reveals the player has
	bool buttonRevealed = false; //bool for if a button is currently being revealed
	int buttonActiveCount; //count for the amount of active buttons
	GameDifficulty m_difficulty; //how hard the game is

};

#endif // !MATCHGAME

