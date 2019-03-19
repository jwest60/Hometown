#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

#include "tile_manager.h"
#include "layer.h"

class Map : public sf::Drawable
{
public:

	Map(const unsigned int width, const unsigned int height, const unsigned int tile_size);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void load(const std::string& file_name);
	void create_tiles(const sf::Texture& sheet, const std::string& atlas);
	std::unique_ptr<Layer>& create_layer();
	void generate();
	void clear();

private:

	std::vector<std::unique_ptr<Layer> > layers;

	Tile_Manager t_manager;

	const unsigned int width;
	const unsigned int height;
	const unsigned int tile_size;
};