#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/game.hpp"
#include "../include/game_state_menu.hpp"

int main()
{
	Game game;

	game.push_state(new Game_State_Menu(&game));
	game.game_loop();

	return 0;
}