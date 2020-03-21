#include "../include/tile_manager.hpp"

using json = nlohmann::json;

Tile_Manager::Tile_Manager()
{
	tile_string_id["grass"] = ID::grass;
}

Tile& Tile_Manager::get_tile(const std::string& name)
{
	return this->tiles[name];
}

void Tile_Manager::create_tiles(const sf::Texture& sheet, const std::string& atlas)
{
	std::ifstream i;
	json j;
	i.open(atlas);
	if (i.fail()) { std::cerr << "warning: failed to open atlas " << atlas << std::endl; return; }
	i >> j;
	i.close();

	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		std::string name = it.key();

		unsigned int left = it->find("left").value();
		unsigned int top = it->find("top").value();
		unsigned int size = it->find("size").value();
		bool solid = it->find("solid").value();

		sf::IntRect rect(left, top, size, size);

		// Tile(ID id, const sf::Texture& tex, const sf::IntRect& tex_rect, unsigned int tile_size, bool solid);

		ID id;

		try
		{
			id = this->tile_string_id[name];
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "warning: trying to create tile for unknown id " << name << std::endl;
		}

		this->tiles.emplace(name, Tile(id, sheet, rect, size, solid));
	}

	return;
}