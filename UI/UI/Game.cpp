#include "Game.h"
#include "Menu.h"
#include"Options.h"
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/
static double const MS_PER_UPDATE = 10.0;

Game::Game() : window(sf::VideoMode(800, 600), "Michael & Davids Match Game")
{
	//load background music
	if (!m_bufferMusic.loadFromFile("background Music.wav"))
	{

	}
	m_music.setBuffer(m_bufferMusic);
	m_music.setLoop(true); //loop
	m_music.play();

	if (!m_font.loadFromFile("Figurativative.ttf"))
	{
		std::cout << "problem loading font file " << std::endl;  //font
	}

	m_licenseScreen = new License(*this, m_font);
	m_splashScreen = new Splash(*this, m_font);
	m_menu = new Menu(window.getSize().x / 4, window.getSize().y / 2, *this, window);
	m_options= new Options(window.getSize().x / 4, window.getSize().y / 2, *this);
	m_help = new HelpScreen(window.getSize().x / 4, window.getSize().y / 2, *this);
	m_matchGame = new MatchGame(window.getSize().x / 8, window.getSize().y / 2, *this, window, m_gameDiff);
}

Game::~Game(){}


//run
void Game::run()
{

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	//What happens while the window is open
	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{

			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		draw();
	}

}

//process events
void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (m_gameState)
		{
			case GameState::TheMenu:
				break;
			case GameState::Playing:
				break;
			case GameState::TheOptions:
				break;
			case GameState::TheLicense:
				break;
			case GameState::TheSplash:
				break;
			case GameState::Help:
				break;
			default:
				break;
				}
		}

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		processGameEvents(event);
	}



void Game::processGameEvents(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		break;
	case sf::Event::KeyReleased:
		break;
	default:
		break;
	}
}
void Game::initialize()
{
	isRunning = true;
}

//update loop where all the screens updates are handled
void Game::update(sf::Time  dt)
{
	switch (m_gameState)
	{
	case GameState::TheLicense:
		m_licenseScreen->update(dt);
		break;
	case GameState::TheSplash:
		m_xbox.update();
		if (m_xbox.m_currentState.Start == true && !m_xbox.m_previousState.Start || sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) //press start to transition to menu
		{
			m_isKeyPressed = true;
		}
		if (m_isKeyPressed == true)
		{
			m_splashScreen->wiper(dt);
		}
		break;
	case GameState::TheMenu:
		m_menu->update();
		break;
	case GameState::TheOptions:
		m_options->update();
		break;
	case GameState::Help:
		m_help->update();
		break;

	case GameState::Playing:
		m_matchGame->update();
	default:
		break;
	}
	
}
//draw all the screens of the game
void Game::draw()
{
	
	switch (m_gameState)
	{
	case GameState::TheMenu:
		window.clear(sf::Color(0, 0, 0, 0));
		m_menu->draw();
		window.display();
		break;

	case GameState::TheOptions:
		window.clear(sf::Color(0, 0, 0, 0));
		m_options->draw(window);
		window.display();
		break;
	case GameState::TheLicense:
		m_licenseScreen->render(window);
		break;
	case GameState::TheSplash:
		m_splashScreen->render(window);
		break;
	case GameState::Help:
		window.clear(sf::Color(0, 0, 0, 0));
		m_help->draw(window);
		window.display();
		break;
	case GameState::Playing:
		window.clear(sf::Color(0, 0, 0, 0));
		m_matchGame->draw();
		window.display();
		break;
	default:
		break;
	}
	
	

}

void Game::unload()
{
	std::cout << "Cleaning up" << std::endl;
}

//set the gamestate of the game
void Game::setGameState(GameState gameState)
{
	m_gameState = gameState;
}

//set the difficulty for matchgame
void Game::setGameDifficulty(GameDifficulty gameDiff)
{
	m_gameDiff = gameDiff;
	m_matchGame->initialise(m_gameDiff); //update match game with the new difficulty
}

//simple check for the gamestate
GameState Game::getGameState()
{
	return GameState(m_gameState);
}
