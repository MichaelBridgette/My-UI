#include "MatchGame.h"
#include<string>
/*
Created By: Michael Bridgette & David O'Gorman
Date: 02/03/2017
Hours Spent: ~15hours
Summary: A simple sfml game with menu, options that use the common UI elements
*/

//match game, player must guess what button contains a word based on the buttons size
MatchGame::MatchGame(float width, float height, Game & game, sf::RenderWindow & window, GameDifficulty difficulty):
	m_game(&game),
	m_window(window),
	m_width(width),
	m_height(height)
{
	initialise(difficulty); //setup game
}

//setup all the games variables
void MatchGame::initialise(GameDifficulty difficulty)
{
	m_difficulty = difficulty; //difficulty
	m_gui.removeAllElements(); //clear all the elements, useful when starting new game and new elements need to be added
	m_widgets.clear(); //clear the widgets container
	m_tags.clear(); //clear the tags

	m_selectedItemIndex = 0; //start at top
	tagsIndex = 0;
	wantedTag = "";

	m_tags.push_back("Dog");
	m_tags.push_back("Cat");
	m_tags.push_back("Bird");
	m_tags.push_back("Pizza"); //tags to be guessed by the player

	
	//add all the buttons for the game
	m_widgets.push_back(new Button("Dog", (m_width* 1.5), float(m_height / (MAX_ITEMS + 0.2f)), sf::Color::White, "Dog"));
	m_widgets.push_back(new Button("Cat", (m_width * 2.5), float(m_height / (MAX_ITEMS + 0.2f)), sf::Color::White, "Cat"));
	m_widgets.push_back(new Button("Bird", (m_width * 3.5), float(m_height / (MAX_ITEMS + 0.2f)), sf::Color::White, "Bird"));
	m_widgets.push_back(new Button("Pizza", (m_width * 4.5), float(m_height / (MAX_ITEMS + 0.2f)), sf::Color::White, "Pizza")); 
	m_widgets[0]->getFocus();

	//bind the same function all the buttons
	m_widgets[0]->Enter = std::bind(&MatchGame::checkMatch, this);
	m_widgets[1]->Enter = std::bind(&MatchGame::checkMatch, this);
	m_widgets[2]->Enter = std::bind(&MatchGame::checkMatch, this);
	m_widgets[3]->Enter = std::bind(&MatchGame::checkMatch, this);

	//if the game is on medium add extra tags and extra buttons
	if (difficulty == GameDifficulty::Medium)
	{
		m_tags.push_back("Battery");
		m_tags.push_back("Poo");
		m_tags.push_back("Lemonade");
		m_tags.push_back("Apple");
		m_widgets.push_back(new Button("Battery", (m_width* 1.5), float(m_height / (MAX_ITEMS + 0.2f))*2, sf::Color::White, "Battery"));
		m_widgets.push_back(new Button("Poo", (m_width * 3.5), float(m_height / (MAX_ITEMS + 0.2f))*2, sf::Color::White, "Poo"));
		m_widgets.push_back(new Button("Lemonade", (m_width * 4.5), float(m_height / (MAX_ITEMS + 0.2f))*2, sf::Color::White, "Lemonade"));
		m_widgets.push_back(new Button("Apple", (m_width * 6.5), float(m_height / (MAX_ITEMS + 0.2f))*2, sf::Color::White, "Apple"));
		m_widgets[4]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[5]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[6]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[7]->Enter = std::bind(&MatchGame::checkMatch, this);
	}

	//if the game is on hard, then add even more
	if (difficulty == GameDifficulty::Hard)
	{
		m_tags.push_back("Battery");
		m_tags.push_back("Poo");
		m_tags.push_back("Lemonade");
		m_tags.push_back("Apple");
		m_widgets.push_back(new Button("Battery", (m_width* 1.5), float(m_height / (MAX_ITEMS + 0.2f)) * 2, sf::Color::White, "Battery"));
		m_widgets.push_back(new Button("Poo", (m_width * 3.5), float(m_height / (MAX_ITEMS + 0.2f)) * 2, sf::Color::White, "Poo"));
		m_widgets.push_back(new Button("Lemonade", (m_width * 4.5), float(m_height / (MAX_ITEMS + 0.2f)) * 2, sf::Color::White, "Lemonade"));
		m_widgets.push_back(new Button("Apple", (m_width * 6.5), float(m_height / (MAX_ITEMS + 0.2f)) * 2, sf::Color::White, "Apple"));
		m_widgets[4]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[5]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[6]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[7]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_tags.push_back("Phone");
		m_tags.push_back("Armadillo");
		m_tags.push_back("Pete is cool");
		m_tags.push_back("Hi");
		m_widgets.push_back(new Button("Phone", (m_width), float(m_height / (MAX_ITEMS + 0.2f)) * 3, sf::Color::White, "Phone"));
		m_widgets.push_back(new Button("Armadillo", (m_width * 2.5), float(m_height / (MAX_ITEMS + 0.2f)) * 3, sf::Color::White, "Armadillo"));
		m_widgets.push_back(new Button("Pete is cool", (m_width * 4.5), float(m_height / (MAX_ITEMS + 0.2f)) * 3, sf::Color::White, "Pete is cool"));
		m_widgets.push_back(new Button("Hi", (m_width * 7.0), float(m_height / (MAX_ITEMS + 0.2f)) * 3, sf::Color::White, "Hi"));
		m_widgets[8]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[9]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[10]->Enter = std::bind(&MatchGame::checkMatch, this);
		m_widgets[11]->Enter = std::bind(&MatchGame::checkMatch, this);
	}

	m_gui.both = true; // control scheme

	m_label = new Label("Find", (m_width), float(m_height / (MAX_ITEMS + 0.2f) * 5.5)); //label that displays the wanted tag/button
 
	m_label2 = new Label(("Reveals Remaining: "+std::to_string(revealCounter)), (m_width), float(m_height / (MAX_ITEMS + 0.2f) * 4));
	m_label2->changeTextSize(20);

	m_icon[0] = new Label("Select", (m_width), float(m_height / (MAX_ITEMS + 0.2f) * 7.5), "a button.png");
	m_icon[1] = new Label("Back", (m_width*2), float(m_height / (MAX_ITEMS + 0.2f) * 7.5), "b button.png");
	m_icon[2] = new Label("Reveal", (m_width * 3), float(m_height / (MAX_ITEMS + 0.2f) * 7.5), "y button.png"); //icons
	//add all the labelss
	m_gui.addLabel(m_label);
	m_gui.addLabel(m_label2);
	m_gui.addLabel(m_icon[0]);
	m_gui.addLabel(m_icon[1]);
	m_gui.addLabel(m_icon[2]);

	//add all the buttons
	for each  (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}

	if (!m_texture.loadFromFile("background.jpg"))
	{
		//handle
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0, 0);

	revealCounter = 3;
	buttonActiveCount = 0;

	m_timer.restart();
	updateTag();
}

//draw all the games elements
void MatchGame::draw()
{
	m_window.draw(m_sprite);
	m_gui.draw(m_window);
}

//update all the games elements
void MatchGame::update()
{
	m_xbox.update();
	
	//press y to reveal a buttons tag
	if (m_xbox.m_currentState.Y == true && !m_xbox.m_previousState.Y)
	{
		if (revealCounter > 0)
		{
			reveal();
			revealCounter--;
			m_label2->updateText("Reveals Remaining: "+std::to_string(revealCounter));
		}
	}
	
	else
	{
		m_gui.update(m_selectedItemIndex, m_widgets.size());
	}


	//hide the button
	if (buttonRevealed&&m_timer.getElapsedTime().asSeconds()>3)
	{
		hide();
		buttonRevealed = false;
	}

	//go back to the menu
	if (m_xbox.m_currentState.B == true&& !m_xbox.m_previousState.B)
	{
		m_game->setGameState(GameState::TheMenu);
	}

	//checks for game over
	if (m_difficulty == GameDifficulty::Easy)
	{
		if (m_widgets[0]->isActive == false && m_widgets[1]->isActive == false && m_widgets[2]->isActive == false && m_widgets[3]->isActive == false )
		{
			m_label->updateText("Game Over");
		}
	}
	if (m_difficulty == GameDifficulty::Medium)
	{
		if (m_widgets[0]->isActive == false && m_widgets[1]->isActive == false && m_widgets[2]->isActive == false && m_widgets[3]->isActive == false && m_widgets[4]->isActive == false && m_widgets[5]->isActive == false && m_widgets[6]->isActive == false && m_widgets[7]->isActive == false)
		{
			m_label->updateText("Game Over");
		}
	}
	if (m_difficulty == GameDifficulty::Hard)
	{
		if (m_widgets[0]->isActive == false && m_widgets[1]->isActive == false && m_widgets[2]->isActive == false && m_widgets[3]->isActive == false && m_widgets[4]->isActive == false && m_widgets[5]->isActive == false && m_widgets[6]->isActive == false && m_widgets[7]->isActive == false&& m_widgets[8]->isActive == false && m_widgets[9]->isActive == false && m_widgets[10]->isActive == false && m_widgets[11]->isActive == false)
		{
			m_label->updateText("Game Over");
		}
	}
}

//makes button transparent to show its tag
void MatchGame::reveal()
{
	buttonRevealed = true;
	m_widgets[m_selectedItemIndex]->setRectColor(sf::Color::Transparent);
	m_timer.restart();
}

//covers tag of the button
void MatchGame::hide()
{
	for (int i = 0; i < m_widgets.size();i++)
	{
		m_widgets[i]->setRectColor(sf::Color::White);
	}
}

//checks if the wanted tag is the same as the buttons tag
void MatchGame::checkMatch()
{
	if (m_widgets[m_selectedItemIndex]->checkTag() == wantedTag)
	{
		m_widgets[m_selectedItemIndex]->isActive = false;
		updateTag();
	}
}

//move onto the next wanted tag
void MatchGame::updateTag()
{	
	wantedTag = m_tags[tagsIndex];
	if (tagsIndex < m_tags.size()-1)
	{
		tagsIndex++;
	}
	m_label->updateText("Find " + wantedTag);
	
}
