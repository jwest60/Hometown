#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.h"
#include "game_state_play.h"

int main()
{
	Game game;

	game.push_state(new Game_State_Play(&game));
	game.game_loop();

	return 0;
}