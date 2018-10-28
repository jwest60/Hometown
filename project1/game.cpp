#include "game.h"
#include "game_state.h"

void Game::push_state(Game_State* state)
{
	this->states.push(state);
}

void Game::pop_state()
{
	if (this->states.empty()) return;

	delete this->states.top();

	this->states.pop();
}

void Game::change_state(Game_State* state)
{
	this->pop_state();

	this->push_state(state);
}

Game_State* Game::peek_state()
{
	if (this->states.empty()) return nullptr;

	return this->states.top();
}

void Game::game_loop()
{
	sf::Clock clock;

	float dt = clock.restart().asMilliseconds();

	while (this->window.isOpen())
	{
		if (this->peek_state() == nullptr) continue;

		this->peek_state()->handle_input();
		this->peek_state()->update(dt);
		this->window.clear(sf::Color::Black);
		this->peek_state()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Game");
}

Game::~Game()
{
	while (!this->states.empty()) { this->pop_state(); }
}