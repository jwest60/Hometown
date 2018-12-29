#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "tile.h"
#include "tile_manager.h"


class Map : public sf::Drawable
{
public:

	Map(const unsigned int width, const unsigned int height, const unsigned int tile_size);

	void create();

	void create_tiles(const sf::Texture& sheet, const std::string& atlas);

private:

	std::vector<Tile> tiles;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	const unsigned int width;
	const unsigned int height;
	const unsigned int tile_size;

	void set_tile_positions();

	Tile_Manager t_manager;
};