#include "game_state_play.h"

#include <iostream>

void Game_State_Play::draw(const float dt)
{
	this->game->window.draw(player);

	return;
}

void Game_State_Play::update(const float dt)
{
	return;
}

void Game_State_Play::handle_input(const float dt)
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

	player.get_input(dt);
}

void Game_State_Play::load_textures()
{
	this->tex_mgr.create_texture("player", "res/character.png");
}

Game_State_Play::Game_State_Play(Game* game)
{
	this->game = game;
	this->load_textures();
	this->player.sprite.setTexture(this->tex_mgr.get_texture("player"));
}