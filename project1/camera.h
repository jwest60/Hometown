#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"

class Camera
{
public:

	Camera();

	Camera(Entity* target);

	void update(const float dt);

	void set_target(Entity* target);
	void set_size(const sf::Vector2f& size);

	sf::View& get_view();

private:

	sf::View camera;

	Entity* target;

	float zoom_level;
};