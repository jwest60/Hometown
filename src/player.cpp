#include "../include/player.hpp"

sf::Vector2f Player::get_movement(const float dt)
{
	int h_move = sf::Keyboard::isKeyPressed(sf::Keyboard::D)
		- sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	int v_move = sf::Keyboard::isKeyPressed(sf::Keyboard::S)
		- sf::Keyboard::isKeyPressed(sf::Keyboard::W);

	return sf::Vector2f(h_move * this->speed * dt, v_move * this->speed * dt);
}

void Player::get_input()
{
	
}