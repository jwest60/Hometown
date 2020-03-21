#pragma once

#include <map>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "tile.hpp"
#include "../nlohmann/json.hpp"

class Tile_Manager
{
public:

	Tile_Manager();

	void create_tiles(const sf::Texture& sheet, const std::string& atlas);

	Tile& get_tile(const std::string& name);

private:

	std::map<std::string, Tile> tiles;

	std::unordered_map<std::string, ID> tile_string_id;

	unsigned int tile_size;
};