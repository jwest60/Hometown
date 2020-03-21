#pragma once

#include "../include/Game_State_Menu.hpp"
#include "../include/Game_State_Play.hpp"

#include <iostream>

Game_State_Menu::Game_State_Menu(Game* game)
{
	this->game = game;
}

void Game_State_Menu::draw(const float dt)
{
	return;
}

void Game_State_Menu::update(const float dt)
{
	return;
}

void Game_State_Menu::handle_input(const float dt)
{
	sf::Event event;
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(this->game->window);

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::KeyPressed:
			this->load_state(new Game_State_Play(this->game));
		default:
			break;
		}

		this->gui.handle_event(mouse_pos, event);
	}

	this->gui.handle_input(mouse_pos);
}

void Game_State_Menu::load_state(Game_State *state)
{
	this->game->change_state(state);
}