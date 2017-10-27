#include "Menu.h"

/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//main menu of the game
Menu::Menu(float width, float height, Game & game, sf::RenderWindow &window) :
	m_label("MATCH GAME", width / 2, (height / MAX_ITEMS + 2.0f)*0.5f),
	m_game(&game),
	m_window(window)
{
	m_itemSelected = false;
	m_label.setUnderLined();
	m_widgets[0] = new Button("Play Game", (width / 2), float (height/(MAX_ITEMS + 0.2f) * 2.0f));
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&Menu::GoToPlay, this); //func bind
	m_widgets[1] = new Button("Options", (width / 2), (height / (MAX_ITEMS + 0.2f) * 3));
	m_widgets[1]->Enter = std::bind(&Menu::GoToOptions, this); //func binf
	m_widgets[2] = new Button("End Game", (width / 2), (height / (MAX_ITEMS + 0.2f) * 4));  //dynamic placements
	m_widgets[2]->Enter = std::bind(&Menu::EndGame, this); //bind
	m_selectedItemIndex = 0; //start at top 

	m_gui.vertical = true; //control scheme

	if (!m_texture.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);

	//add ui elements to gui
	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}
	m_gui.addLabel(&m_label);


	m_icon[0]= new Label("Select", width / 10, (height / (MAX_ITEMS + 0.2f)) * 6, "a button.png");
	m_icon[1] = new Label("Help", (width / 10) + 100, (height / (MAX_ITEMS + 0.2f)) * 6, "y button.png");
	m_icon[2] = new Label("Move", (width / 10) + 180, (height / (MAX_ITEMS + 0.2f)) * 6, "d pad.png"); //menu icons
	
	for each (Label* icon in m_icon)
	{
		m_gui.addLabel(icon);
	}

}


Menu::~Menu()
{
}

/*
Draw the ui elements
*/
void Menu::draw( )
{
	m_window.draw(m_sprite);
	m_gui.draw(m_window);
}

//update ui elements
void Menu::update()
{
	

	m_gui.update(m_selectedItemIndex, MAX_ITEMS);
	m_xbox.update();

	if (m_xbox.m_currentState.Y == true && !m_xbox.m_previousState.Y)
	{
		m_game->setGameState(GameState::Help);
		std::cout << "You will not get any help" << std::endl;
	}
	
}

//return selected item NOTE: not used
bool Menu::itemSelected()
{
	return m_itemSelected;
}

//change gamestate to play
void Menu::GoToPlay()
{
	m_game->setGameState(GameState::Playing);
}

//end the game
void Menu::EndGame()
{
	m_window.close();
}

//go to the options
void Menu::GoToOptions()
{
	m_game->setGameState(GameState::TheOptions);
}
