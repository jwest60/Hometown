#include "Layer.h"

Layer::Layer(const unsigned int width, const unsigned int height, const unsigned int tile_size)
	: width(width), height(height), tile_size(tile_size), visible(true)
{
	this->tiles.resize(width * height);
}

void Layer::set_tile_positions()
{
	for (int y = 0; y < this->width; ++y)
		for (int x = 0; x < this->height; ++x)
			this->tiles[y * this->width + x].sprite.setPosition(x * this->tile_size, y * this->tile_size);
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < this->tiles.size(); ++i)
		if (this->visible) target.draw(this->tiles[i]);
}

void Layer::flood_fill(Tile& tile)
{
	for (size_t i = 0; i < this->width * this->height; ++i)
		this->tiles[i] = tile;
}

void Layer::place_tile(Tile& tile, sf::Vector2i& pos)
{
	this->tiles[pos.y * this->width + pos.x] = tile;

	return;
}