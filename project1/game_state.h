#pragma once

#include "game.h"
#include "texture_manager.h"

class Game_State
{
public:

	Game* game;
	
	Texture_Manager tex_mgr;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handle_input() = 0;
};