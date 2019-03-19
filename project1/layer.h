#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.h"
#include "tile_manager.h"


struct Layer : public sf::Drawable
{
	Layer(const unsigned int width, const unsigned int height, const unsigned int tile_size);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void set_tile_positions();
	void flood_fill(Tile& tile);
	void place_tile(Tile& tile, sf::Vector2i& pos);

	const unsigned int width;
	const unsigned int height;
	const unsigned int tile_size;

	int depth;
	// std::string name;

	bool visible;

	std::vector<Tile> tiles;
};