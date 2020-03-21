#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

class Game_State;

class Game
{
public:

	sf::RenderWindow window;

	void push_state(Game_State* state);
	void pop_state();
	void change_state(Game_State* state);
	Game_State* peek_state();

	void game_loop();

	Game();
	~Game();

private:

	std::stack<Game_State*> states;
};