#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <cmath>

class Camera
{
public:

	Camera();

	Camera(Entity* target, sf::IntRect bounds);

	void update(const float dt);

	void set_target(Entity* target);
	void set_size(const sf::Vector2f& size);

	void set_bounds(const sf::FloatRect bounds);

	sf::View& get_view();

private:

	sf::View camera;

	sf::FloatRect bounds;

	Entity* target;

	float zoom_level;

	const float follow_speed = 0.1f;
};