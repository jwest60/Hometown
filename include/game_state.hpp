#pragma once

#include "game.hpp"
#include "texture_manager.hpp"

class Game_State
{
public:

	Game* game;
	
	Texture_Manager tex_mgr;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handle_input(const float dt) = 0;
};