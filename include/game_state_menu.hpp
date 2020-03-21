#pragma once

#include "game_state.hpp"
#include "gui.hpp"

class Game_State_Menu : public Game_State
{
public:

	Game_State_Menu(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handle_input(const float dt);

private:

	Gui gui;

	void load_state(Game_State *state);
};