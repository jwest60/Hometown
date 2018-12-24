#include "player.h"
#include <iostream>

Player::Player() :
	speed(200.f),
	width(16),
	height(32) {}


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

	h_move || v_move ? this->anim_handler.play() : this->anim_handler.stop();

	this->change_animation(h_move, v_move);
	this->sprite.move(h_move * this->speed * dt, v_move * this->speed * dt);
}

void Player::change_animation(int h_move, int v_move)
{
	if (h_move == 1)
		this->anim_handler.set_animation("right");
	if (h_move == -1)
		this->anim_handler.set_animation("left");
	if (v_move == 1)
		this->anim_handler.set_animation("down");
	if (v_move == -1)
		this->anim_handler.set_animation("up");
}

void Player::update_sprite(const float dt)
{
	this->anim_handler.update_frame(dt);
	this->set_frame(this->anim_handler.get_current_frame());
}

void Player::set_texture(sf::Texture& tex, const std::string& atlas_name)
{ 
	this->sprite.setTexture(tex);
	this->anim_handler.create_animations(tex, atlas_name);
	this->set_frame(this->anim_handler.get_current_frame());
}

void Player::set_frame(sf::IntRect& frame) { this->sprite.setTextureRect(frame); }