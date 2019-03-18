#include "map.h"

Map::Map(const unsigned int width, const unsigned int height, const unsigned int tile_size)
	: width(width), height(height), tile_size(tile_size) {}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < this->layers.size(); ++i)
		target.draw(*layers[i]);
}

void Map::create_tiles(const sf::Texture& sheet, const std::string& atlas)
{
	this->t_manager.create_tiles(sheet, atlas);
}

std::unique_ptr<Layer>& Map::create_layer()
{
	this->layers.push_back(std::make_unique<Layer>(this->width, this->height, this->tile_size));

	return this->layers[this->layers.size() - 1];
}

void Map::load(const std::string& file_name)
{
	return;
}

void Map::generate()
{
	this->clear();

	auto& tiles1 = this->create_layer();
	auto& tiles2 = this->create_layer();

	tiles1->flood_fill(this->t_manager.get_tile("grass"));
	tiles1->set_tile_positions();

	tiles2->place_tile(this->t_manager.get_tile("rock"), sf::Vector2i(2, 2));
	tiles2->set_tile_positions();
}

void Map::clear()
{
	this->layers.clear();
}