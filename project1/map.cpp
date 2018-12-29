#include "map.h"

Map::Map(const unsigned int width, const unsigned int height, const unsigned int tile_size) 
	: width(width), height(height), tile_size(tile_size) {}

void Map::create()
{
	for (int i = 0; i < width * height; ++i)
	{
		this->tiles.push_back(this->t_manager.get_tile("grass"));
	}

	set_tile_positions();
}

void Map::set_tile_positions()
{
	for (int y = 0; y < this->width; ++y)
	{
		for (int x = 0; x < this->height; ++x)
		{
			this->tiles[y * this->width + x].sprite.setPosition(x * this->tile_size, y * this->tile_size);
		}
	}
}

void Map::create_tiles(const sf::Texture& sheet, const std::string& atlas)
{
	this->t_manager.create_tiles(sheet, atlas);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int y = 0; y < this->width; ++y)
	{
		for (int x = 0; x < this->height; ++x)
		{
			target.draw(this->tiles[y * this->width + x]);
		}
	}
}