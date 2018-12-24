#pragma once

#include <SFML/Graphics.hpp>
#include "animation_handler.h"

class Player : public sf::Drawable
{
public:
	Player();

	void get_input(const float dt);

	float get_speed() { return this->speed; }
	float get_width() { return this->width; }
	float get_height() { return this->height; }

	void set_texture(sf::Texture& tex, const std::string& atlas_name);

	void update_sprite(const float dt);

private:

	sf::Sprite sprite;

	void set_frame(sf::IntRect& frame);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Animation_Handler anim_handler;
	void change_animation(int h_move, int v_move);

	const float speed;
	const int width;
	const int height;
};