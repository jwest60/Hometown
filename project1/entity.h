#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>

#include "animation_handler.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Entity : public sf::Drawable
{
public:

	Entity();

	void move(const sf::Vector2f& pos);
	sf::Vector2f get_center() { return this->sprite.getPosition(); }

	void set_texture(sf::Texture& tex, const std::string& atlas_name);
	void update_sprite(const float dt);

	float get_speed() { return this->speed; }
	float get_width() { return this->width; }
	float get_height() { return this->height; }

	sf::FloatRect get_entity_bounds();

protected:

	sf::Sprite sprite;

	void set_frame(sf::IntRect& frame);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Animation_Handler anim_handler;
	void change_animation(int h_move, int v_move);

	sf::FloatRect bounding_box;
	void load_bounding_box(const std::string& atlas_name);

	const float speed;
	const int width;
	const int height;
};