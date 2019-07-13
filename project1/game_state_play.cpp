#include "game_state_play.h"

#include <iostream>

Game_State_Play::Game_State_Play(Game* game) : map(20, 20, 16), cols(20, 20, 16)
{
	this->game = game;
	this->camera.set_size(sf::Vector2f(400.f, 300.f));
	this->gui.set_view_size(this->game->window.getSize());

	this->load_textures();
	this->set_textures();

	this->set_gui();

	this->camera.set_target(&(this->player));

	this->map.create_tiles(this->tex_mgr.get_texture("overworld"), "res/overworld_atlas.json");
	this->map.generate();
}

void Game_State_Play::draw(const float dt)
{
	this->game->window.setView(this->camera.get_view());
	this->game->window.draw(this->map);
	this->game->window.draw(this->player);

	this->game->window.setView(this->gui.get_view());
	this->game->window.draw(this->gui);

	return;
}

void Game_State_Play::update(const float dt)
{
	this->player.update_sprite(dt);
	this->camera.update(dt);

	// std::cout << int(1 / dt) << std::endl;

	return;
}

void Game_State_Play::handle_input(const float dt)
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
			if (event.key.code == sf::Keyboard::Tab)
				this->gui.toggle_component_visibility("inventory");
		default:
			break;
		}

		this->gui.handle_event(mouse_pos, event);
	}

	this->gui.handle_input(mouse_pos);

	sf::Vector2f move = this->player.get_movement(dt);
	sf::Vector2f new_pos = this->cols.entity_adjust_position(move, this->player.get_entity_bounds());
	this->player.move(new_pos);
}

void Game_State_Play::load_textures()
{
	this->tex_mgr.create_texture("player", "res/character.png");
	this->tex_mgr.create_texture("overworld", "res/overworld.png");
	this->tex_mgr.create_texture("inventory", "res/inventory.png");
	this->tex_mgr.create_texture("itembox", "res/itembox.png");
	this->tex_mgr.create_texture("itemicon", "res/itemicon.png");

	this->tex_mgr.create_font("main", "res/main.ttf");
	this->tex_mgr.create_font("main2", "res/VCR_OSD_MONO_1.001.ttf");
}

void Game_State_Play::set_textures()
{
	this->player.set_texture(this->tex_mgr.get_texture("player"), "res/character_atlas.json");

	this->gui.items_set_textures(&this->tex_mgr.get_texture("itembox"), &this->tex_mgr.get_texture("itemicon"));
	this->gui.set_font(&this->tex_mgr.get_font("main2"));
}

void Game_State_Play::set_gui()
{
	this->gui.render_component("inventory", this->tex_mgr.get_texture("inventory"));

	this->gui.set_scale(2.0f);
}