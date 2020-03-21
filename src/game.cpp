#include "../include/game.hpp"
#include "../include/game_state.hpp"
#include <iostream>

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

	while (this->window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		if (this->peek_state() == nullptr) continue;

		this->peek_state()->handle_input(dt);
		this->peek_state()->update(dt);
		this->window.clear(sf::Color::Black);
		this->peek_state()->draw(dt);
		this->window.display();
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "Game");
	this->window.setFramerateLimit(60);
}

Game::~Game()
{
	while (!this->states.empty()) { this->pop_state(); }
}