#pragma once

#include "game_state.h"
#include "player.h"
#include "camera.h"

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
};