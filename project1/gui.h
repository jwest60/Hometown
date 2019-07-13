#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <memory>

#include "gui_component.h"
#include "inventory.h"
#include "item_atlas.h"

class Gui : public sf::Drawable
{
public:

	Gui();

	void handle_input(const sf::Vector2i& mouse_pos);
	void handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event);

	void render_component(const std::string& component, sf::Texture& tex);
	void toggle_component_visibility(const std::string& component);

	void items_set_textures(sf::Texture* itembox, sf::Texture* itemicons);

	void set_font(sf::Font* font);

	sf::View& get_view();

	void set_view_size(const sf::Vector2u& size);

	void set_scale(const float scalar);

private:

	void create_components();
	void create_shroud();

	Item_Atlas item_atlas;

	void show_component(const std::string& component);
	void hide_component(const std::string& component);

	void transform_components(const float scalar);
	void center_component(Gui_Component& component);

	std::vector<Gui_Component *> draw_stack;

	std::map<std::string, std::unique_ptr<Gui_Component> > components;

	float gui_scale;

	sf::View view;

	bool draw_shroud;
	sf::RectangleShape shroud;

	sf::Font* font;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};