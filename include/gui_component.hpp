#pragma once

#include <SFML/Graphics.hpp>

class Gui_Component : public sf::Drawable, public sf::Transformable
{
public:

	bool is_visible() { return this->visible; }

	void set_visible(bool v) { this->visible = v; }

	virtual void handle_input(const sf::Vector2i mouse_pos) = 0;
	virtual void handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event) = 0;

protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	bool visible;
};