#include "game_state_play.h"

#include <iostream>

void Game_State_Play::draw(const float dt)
{
	this->game->window.draw(player);

	return;
}

void Game_State_Play::update(const float dt)
{
	this->player.update_sprite(dt);

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

void Game_State_Play::set_textures()
{
	this->player.set_texture(this->tex_mgr.get_texture("player"), "res/character_atlas.json");
}

Game_State_Play::Game_State_Play(Game* game) 
{
	this->game = game;
	this->load_textures();
	this->set_textures();
}