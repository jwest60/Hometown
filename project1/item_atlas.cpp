#include "item_atlas.h"

Item::Item(const unsigned int id, const std::string& name, const std::string& description, Item_Type type, Item_Quality quality)
	: id(id), name(name), description(description), type(type), quality(quality) {}

unsigned int Item::get_id()
{
	return this->id;
}

std::string Item::get_type()
{
	switch (this->type)
	{
	case Item_Type::HAT:
		return "hat";
	default:
		return "undefined";
	}
}

std::string Item::get_quality()
{
	switch (this->quality)
	{
	case Item_Quality::RARE:
		return "rare";
	case Item_Quality::UNCOMMON:
		return "uncommon";
	case Item_Quality::COMMON:
		return "common";
	default:
		return "common";
	}
}

Item_Atlas::Item_Atlas() {}

void Item_Atlas::set_textures(sf::Texture* item_box, sf::Texture* item_icons)
{
	this->item_box = item_box;
	this->item_icons = item_icons;
}

void Item_Atlas::add_item(const unsigned int id, const std::string& name, const std::string& description, 
	Item_Type type, Item_Quality quality,
	sf::IntRect item_icon_rect, sf::IntRect item_box_rect)
{
	this->items.push_back(std::make_unique<Item>(id, name, description, type, quality));
	Item* item = this->items.back().get();

	item->item_icon.setTexture(*this->item_icons);
	item->item_icon.setTextureRect(item_icon_rect);

	item->item_box.setTexture(*this->item_box);
	item->item_box.setTextureRect(item_box_rect);
}

Item* Item_Atlas::get_item(const int id)
{
	return this->items[id].get();
}

void Item_Atlas::create_items()
{
	this->add_item(0, "Hunky Joe's Hunky Hat",
		"When you are Hunky Joe, only \na hat of the utmost Hunkiness is acceptable.",
		Item_Type::HAT,
		Item_Quality::RARE,
		sf::IntRect(0, 0, 16, 16),
		sf::IntRect(0, 0, 32, 32));
}