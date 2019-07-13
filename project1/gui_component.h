#pragma once

#include <SFML/Graphics.hpp>

class Gui_Component : public sf::Drawable, public sf::Transformable
{
public:

	void set_texture(sf::Texture& tex);

	bool is_visible() { return this->visible; }
	bool is_shrouded() { return this->shrouded; }
	bool uses_items() { return this->items; }

	void set_font(sf::Font* font) { this->font = font; }

	void set_visible(bool v) { this->visible = v; }

	sf::Vector2f get_size();

	virtual void handle_input(const sf::Vector2i mouse_pos) = 0;
	virtual void handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event) = 0;
	virtual void set_gui_positions() = 0;

	sf::Font* font;

protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Sprite sprite;

	bool visible;
	bool items;
	bool shrouded;
};