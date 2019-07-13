#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "gui_component.h"
#include "item_atlas.h"

struct _Inventory_Style
{
	sf::Vector2f inventory_slot_begin;
	unsigned int inventory_slot_offset;
	unsigned int inventory_slot_size;
	unsigned int inventory_slot_padding;

	unsigned int item_viewer_padding;

	sf::Vector2f item_name_padding;
	unsigned int item_description_line_padding;

	sf::FloatRect player_viewer;
	sf::FloatRect hat_slot;
	sf::FloatRect clothes_slot;
	sf::FloatRect inventory_slots;
	sf::FloatRect item_viewer;
	sf::FloatRect item_description_box;

	unsigned int item_name_size;
	unsigned int item_description_size;
	unsigned int item_type_size;

	sf::Color c_item_rare_text{ 0x330bcbff };
	sf::Color c_item_description_text{ 0x9f4b24ff };
	sf::Color c_item_type_text{ 0x9f8a81ff };
};

class Inventory : public Gui_Component
{
public:

	Inventory(Item_Atlas* iatl);

private:

	virtual void handle_input(const sf::Vector2i mouse_pos);
	virtual void handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event);
	virtual void set_gui_positions();

	unsigned int inventory_rows;
	unsigned int inventory_cols;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void draw_item_viewer(sf::RenderTarget& target, Item* item) const;
	void draw_item_icon(sf::RenderTarget& target, Item* item, const unsigned int slot) const;

	int get_slot_at_point(const sf::Vector2i mouse_pos);
	void slot_selected(const unsigned int slot);

	void hold_item(int item);
	void place_item(int item);

	Item* held_item;

	sf::Sprite* item_box;

	sf::Text item_name;
	sf::Text item_type;
	sf::Text item_desc;

	bool draw_item_details;

	std::vector<int> inventory;

	Item_Atlas* item_atlas;

	_Inventory_Style style;
};