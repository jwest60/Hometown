#pragma once

#include <SFML/Graphics.hpp>
#include "animation_handler.h"

class Player : public sf::Drawable
{
public:
	Player(sf::Sprite sprite) : sprite(sprite) {}
	Player() {}

	void get_input(const float dt);

	sf::Sprite sprite;

	sf::IntRect frame;

	float get_speed() { return this->speed; }
	float get_width() { return this->width; }
	float get_height() { return this->height; }

private:

	void set_sprite(sf::IntRect& frame);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Animation_Handler anim_handler;
	void update_sprite(int h_move, int v_move);

	const float speed = 200.f;
	const int width = 16;
	const int height = 32;
};