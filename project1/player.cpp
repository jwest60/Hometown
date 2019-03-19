#include "player.h"

Player::Player()
{
	this->speed = 200.f;
	this->width = 16;
	this->height = 32;
	this->tile_size = 16;

	this->bbox = sf::IntRect(0, 0, this->width, this->height);
}