#pragma once

#include "gui_component.hpp"

#include <functional>

class Button : public Gui_Component
{
public:

	Button();

	std::function<void()> on_press;

	void set_on_press(const std::function<void()> func);

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	virtual void handle_input(const sf::Vector2i mouse_pos);
	virtual void handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event);

	bool active;
};