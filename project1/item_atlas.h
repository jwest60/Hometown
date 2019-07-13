#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

enum class Item_Type
{
	UNDEFINED,
	HAT
};

enum class Item_Quality
{
	COMMON,
	UNCOMMON,
	RARE
};

class Item
{
public:

	Item(const unsigned int id, const std::string& name, const std::string& description, Item_Type type, Item_Quality quality);

	std::string name;
	std::string description;

	sf::Sprite item_icon;
	sf::Sprite item_box;

	std::string get_type();
	std::string get_quality();
	unsigned int get_id();

private:

	unsigned int id;

	Item_Type type;
	Item_Quality quality;

};

class Item_Atlas
{
public:

	Item_Atlas();

	void set_textures(sf::Texture* item_box, sf::Texture* item_icons);

	void create_items();

	Item* get_item(const int id);

private:

	void add_item(const unsigned int id, const std::string& name, const std::string& description, Item_Type type, Item_Quality quality, 
		sf::IntRect item_icon_rect, sf::IntRect item_box_rect);

	sf::Texture* item_box;
	sf::Texture* item_icons;

	std::vector<std::unique_ptr<Item> > items;
};