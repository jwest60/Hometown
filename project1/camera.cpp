#include "camera.h"

Camera::Camera() : zoom_level(1.0f) {}
Camera::Camera(Entity* target) : target(target) {}

void Camera::set_target(Entity* target)
{
	this->target = target;
}

void Camera::set_size(const sf::Vector2f& size)
{
	this->camera.setSize(size);
	this->camera.setCenter(size * 0.5f);
}

void Camera::update(const float dt)
{
	sf::Vector2f center = this->target->get_center();

	this->camera.setCenter(center);
}

sf::View& Camera::get_view() { return this->camera; }