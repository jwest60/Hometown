#include "../include/button.hpp"

Button::Button() {}

void Button::handle_input(const sf::Vector2i mouse_pos)
{
	float mouse_x = mouse_pos.x;
	float mouse_y = mouse_pos.y;
}

void Button::handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->on_press();
}

void Button::set_on_press(const std::function<void()> func)
{
	this->on_press = func;
}