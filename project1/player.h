#pragma once

#include "entity.h"

class Player : public Entity
{
public:

	sf::Vector2f get_movement(const float dt);

	void get_input();

};