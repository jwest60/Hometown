#pragma once

#include "game_state.h"

class Game_State_Play : public Game_State
{
public:

	Game_State_Play(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handle_input();
};