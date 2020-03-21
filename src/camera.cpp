#include "../include/camera.hpp"

Camera::Camera() : zoom_level(1.0f) {}
Camera::Camera(Entity* target, sf::IntRect bounds) : target(target) {}

float static lerp(float a, float b, float t)
{
	return a + t * (b - a);
}

void Camera::set_target(Entity* target)
{
	this->target = target;
}

void Camera::set_size(const sf::Vector2f& size)
{
	this->camera.setSize(size);
	this->camera.setCenter(size * 0.5f);
}

void Camera::set_bounds(const sf::FloatRect bounds)
{
	this->bounds = bounds;
}

void Camera::update(const float dt)
{
	const sf::Vector2f view = this->camera.getSize();
	const sf::Vector2f view_center = this->camera.getCenter();

	sf::Vector2f center = this->target->get_center();

	const float x_offset = view.x / 2;
	const float y_offset = view.y / 2;

	if (center.x - x_offset < bounds.left)
		center.x += std::abs(bounds.left - (center.x - x_offset));
	else if (center.x + x_offset > (bounds.left + bounds.width))
		center.x -= std::abs((bounds.left + bounds.width) - (center.x + x_offset));

	if (center.y - y_offset < bounds.top)
		center.y += std::abs(bounds.top - (center.y - y_offset));
	else if (center.y + y_offset > (bounds.top + bounds.height))
		center.y -= std::abs((bounds.top + bounds.height) - (center.y + y_offset));

	this->camera.setCenter(lerp(view_center.x, center.x, this->follow_speed), 
		lerp(view_center.y, center.y, this->follow_speed));
}

sf::View& Camera::get_view() { return this->camera; }