#pragma once

#include "game_state.hpp"
#include "player.hpp"
#include "camera.hpp"
#include "tile_manager.hpp"
#include "map.hpp"
#include "collision_system.hpp"
#include "gui.hpp"
#include "inventory.hpp"

class Game_State_Play : public Game_State
{
public:

	Game_State_Play(Game* game);

	Player player;

	Camera camera;

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handle_input(const float dt);
	
	void load_textures();
	void set_textures();
	void set_gui();

	Collision_System cols;

	Gui gui;

private:

	Map map;
};