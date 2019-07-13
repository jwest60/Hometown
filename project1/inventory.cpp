#include "inventory.h"

sf::FloatRect create_scaled_floatrect_with_offset(const float left, const float top, const float width, 
	const float height, const float x_offset, const float y_offset, const sf::Vector2f& scale)
{
	return sf::FloatRect(x_offset + (left * scale.x), y_offset + (top * scale.y), width * scale.x, height * scale.y);
}

Inventory::Inventory(Item_Atlas* iatl) : inventory_rows(3), inventory_cols(10), item_atlas(iatl), draw_item_details(false), held_item(nullptr)
{
	this->visible = false;
	this->shrouded = true;
	this->items = true;

	this->inventory.resize(inventory_rows * inventory_cols, -1);

	this->inventory[0] = 0;
	this->inventory[5] = 0;
	this->inventory[14] = 0;
	this->inventory[17] = 0;
}

void Inventory::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(this->sprite, states);

	for (int i = 0; i < this->inventory.size(); ++i)
	{
		if (inventory[i] == -1) continue;
		Item* item = this->item_atlas->get_item(inventory[i]);

		this->draw_item_icon(target, item, i);
	}

	if (this->draw_item_details)
	{
		target.draw(*this->item_box);
		target.draw(this->item_name);
		target.draw(this->item_type);
		target.draw(this->item_desc);
	}
}

void Inventory::draw_item_viewer(sf::RenderTarget& target, Item* item) const
{
	sf::Sprite item_box = item->item_box;
	item_box.setPosition(this->style.item_viewer.left, this->style.item_viewer.top);
	item_box.setScale(this->getScale());
	target.draw(item_box);
}

void Inventory::draw_item_icon(sf::RenderTarget& target, Item* item, const unsigned int slot) const
{
	sf::Sprite item_icon = item->item_icon;

	const float scale = this->getScale().x;
	int offset = this->style.inventory_slot_offset * scale;
	int left = int(this->style.inventory_slots.left);
	int top = int(this->style.inventory_slots.top);
	int padding = this->style.inventory_slot_padding * scale;

	int row = slot / this->inventory_cols;
	int col = slot % this->inventory_cols;

	sf::Vector2f pos;
	pos.x = this->style.inventory_slot_begin.x + (offset * col) + padding;
	pos.y = this->style.inventory_slot_begin.y + (offset * row) + padding;

	item_icon.setPosition(pos);
	item_icon.setScale(this->getScale());
	target.draw(item_icon);
}

void Inventory::set_gui_positions()
{
	sf::Vector2f pos = this->getPosition();
	sf::Vector2f scale = this->getScale();

	this->style.player_viewer = create_scaled_floatrect_with_offset(19.f, 8.f, 64.f, 89.f, pos.x, pos.y, scale);
	this->style.hat_slot = create_scaled_floatrect_with_offset(88.f, 8.f, 20.f, 20.f, pos.x, pos.y, scale);
	this->style.clothes_slot = create_scaled_floatrect_with_offset(88.f, 46.f, 20.f, 20.f, pos.x, pos.y, scale);
	this->style.item_viewer = create_scaled_floatrect_with_offset(15.f, 194.f, 60.f, 60.f, pos.x, pos.y, scale);
	this->style.item_description_box = create_scaled_floatrect_with_offset(83.f, 194.f, 204.f, 60.f, pos.x, pos.y, scale);

	this->style.inventory_slots = create_scaled_floatrect_with_offset(15.f, 110.f, 272.f, 76.f, pos.x, pos.y, scale);
	this->style.inventory_slot_begin = sf::Vector2f(pos.x + (15.f * scale.x), pos.y + (111.f * scale.y));
	this->style.inventory_slot_offset = 28;
	this->style.inventory_slot_size = 20;
	this->style.inventory_slot_padding = 1;

	this->style.item_viewer_padding = 8;

	this->style.item_name_padding = sf::Vector2f(9.f, 4.f);
	this->style.item_description_line_padding = 5;

	this->style.item_type_size = 16;
	this->style.item_description_size = 16;
	this->style.item_name_size = 16;

	unsigned int x = this->style.item_description_box.left + this->style.item_name_padding.x;

	this->item_name.setFont(*this->font);
	this->item_name.setCharacterSize(this->style.item_name_size);
	this->item_name.setColor(this->style.c_item_rare_text);
	this->item_name.setPosition(x, this->style.item_description_box.top + this->style.item_name_padding.y);

	this->item_type.setFont(*this->font);
	this->item_type.setCharacterSize(this->style.item_type_size);
	this->item_type.setColor(this->style.c_item_type_text);
	this->item_type.setPosition(x,
		this->item_name.getPosition().y + this->style.item_name_size + (this->style.item_description_line_padding * this->getScale().y));

	this->item_desc.setFont(*this->font);
	this->item_desc.setCharacterSize(this->style.item_description_size);
	this->item_desc.setColor(this->style.c_item_description_text);
	this->item_desc.setPosition(x,
		this->item_type.getPosition().y + this->style.item_type_size + (this->style.item_description_line_padding * this->getScale().y));
}

void Inventory::handle_input(const sf::Vector2i mouse_pos)
{
	float mouse_x = mouse_pos.x;
	float mouse_y = mouse_pos.y;

	if (this->style.inventory_slots.contains(mouse_x, mouse_y))
	{
		int slot = this->get_slot_at_point(mouse_pos);
		this->slot_selected(this->get_slot_at_point(mouse_pos));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

	}
}

void Inventory::handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int slot = this->get_slot_at_point(mouse_pos);
			held_item != nullptr ? place_item(slot) : hold_item(slot);
		}
	}
}

void Inventory::slot_selected(const unsigned int slot)
{
	if (slot == -1 || this->inventory[slot] == -1)
	{
		this->draw_item_details = false;
		return;
	}

	this->draw_item_details = true;
	Item* item = this->item_atlas->get_item(this->inventory[slot]);

	this->item_box = &item->item_box;
	unsigned int padding = this->style.item_viewer_padding * this->getScale().x;
	this->item_box->setPosition(this->style.item_viewer.left + padding, this->style.item_viewer.top + padding);
	this->item_box->setScale(this->getScale());

	this->item_name.setString(item->name);
	this->item_type.setString(item->get_quality() + " " + item->get_type());
	this->item_desc.setString(item->description);
}

void Inventory::hold_item(int slot)
{
	if (slot == -1 || this->inventory[slot] == -1) return;
	this->held_item = this->item_atlas->get_item(this->inventory[slot]);
	this->inventory[slot] = -1;
}

void Inventory::place_item(int slot)
{
	if (slot == -1 || held_item == nullptr) return;
	unsigned int held_item_id = this->held_item->get_id();
	this->held_item = this->inventory[slot] == -1 ? nullptr : this->item_atlas->get_item(this->inventory[slot]);
	this->inventory[slot] = held_item_id;
}

int Inventory::get_slot_at_point(const sf::Vector2i mouse_pos)
{
	const float scale = this->getScale().x;
	int offset = this->style.inventory_slot_offset * scale;
	int size = this->style.inventory_slot_size * scale;
	int left = int(this->style.inventory_slots.left);
	int top = int(this->style.inventory_slots.top);

	int row = (mouse_pos.x - left) % offset < size ? (mouse_pos.x - left) / offset : -1;
	int col = (mouse_pos.y - top) % offset < size ? (mouse_pos.y - top) / offset : -1;

	if (row == -1 || col == -1) return -1;
	return (col * this->inventory_cols + row);
}