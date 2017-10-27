#pragma once
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
Known Bugs: none
*/
#ifndef GAME
#define GAME

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include"Menu.h"
#include "License.h"
#include "Options.h"
#include "Splash.h"
#include<SFML\Graphics.hpp>
#include"XBOX360CONTROLLER.h"
#include"GUI.h"
#include"Help.h"
#include"MatchGame.h"
class License;
class Splash;
class Menu;
class Options;
class HelpScreen;
class MatchGame;


//the the screens of the game
enum GameState
{
	TheLicense,
	TheSplash,
	TheMenu,
	TheOptions,
	Playing,
	Help
};
//difficultys for Match Game
enum GameDifficulty
{
	Easy,
	Medium,
	Hard

};

class Game
{
public:
	Game();
	~Game();
	void run();
	void processEvents();
	void processGameEvents(sf::Event& event);
	void setGameState(GameState gameState); //change the game state
	void setGameDifficulty(GameDifficulty gameDiff);//change the game difficulty
	GameState getGameState(); //check for state
	sf::SoundBuffer m_bufferMusic; 
	sf::Sound m_music;//background music of the game
	bool useFastAnimation = false;
private:
	sf::RenderWindow window;
	bool isRunning = false;
	void initialize();
	void update(sf::Time dt);
	void draw();
	void unload();
	GameState m_gameState = GameState::TheLicense; //current gamestate
	GameDifficulty m_gameDiff = GameDifficulty::Easy; //current difficulty
	sf::Font m_font;
	MatchGame *m_matchGame; //the match game itself
	Menu *m_menu; //the menu
	Options *m_options; // the options
	License *m_licenseScreen; // the license
	Splash *m_splashScreen; //the splash screen
	HelpScreen *m_help; //simple help screen
	bool m_isKeyPressed;
	Xbox360Controller m_xbox; //xbox controller
	GUI m_gui; //gui 

};
#endif // !Game