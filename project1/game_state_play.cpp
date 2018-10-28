#include "game_state_play.h"

#include <iostream>

Game_State_Play::Game_State_Play(Game* game)
{
	this->game = game;
}

void Game_State_Play::draw(const float dt)
{
	return;
}

void Game_State_Play::update(const float dt)
{
	return;
}

void Game_State_Play::handle_input()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;
		default:
			break;
		}
	}
}