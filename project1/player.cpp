#include "player.h"
#include <iostream>

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}

void Player::get_input(const float dt)
{
	int h_move = sf::Keyboard::isKeyPressed(sf::Keyboard::D) 
		- sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	int v_move = sf::Keyboard::isKeyPressed(sf::Keyboard::S) 
		- sf::Keyboard::isKeyPressed(sf::Keyboard::W);

	this->update_sprite(h_move, v_move);
	this->sprite.move(h_move * this->speed * dt, v_move * this->speed * dt);
}

void Player::update_sprite(int h_move, int v_move)
{
	// moving right
	if (h_move == 1)
		this->anim_handler.set_animation("right");
	// moving left
	if (h_move == -1)
		this->anim_handler.set_animation("left");
	// moving down
	if (v_move == 1)
		this->anim_handler.set_animation("down");
	// moving up
	if (v_move == -1)
		this->anim_handler.set_animation("up");

	this->set_sprite(this->frame);
}

void Player::set_sprite(sf::IntRect& frame)
{
	this->sprite.setTextureRect(frame);
}