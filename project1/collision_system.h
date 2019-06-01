#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "entity.h"

class Collision_System
{
public:

	Collision_System(unsigned int width, unsigned int height, unsigned int tile_size);

	sf::Vector2f entity_adjust_position(sf::Vector2f& pos, sf::FloatRect& bounds);

	bool col_exists_at_point(float x, float y);

private:

	std::vector<Entity *> entities;

	std::vector<bool> collisions;

	unsigned int width;
	unsigned int height;
	unsigned int tile_size;
};