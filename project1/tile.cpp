#include "tile.h"

Tile::Tile(ID id, const sf::Texture& tex, const sf::IntRect& tex_rect, unsigned int tile_size, bool solid)
	: id(id), tile_size(tile_size), solid(solid), sprite(tex, tex_rect)
{

}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}

Tile& Tile::operator=(const Tile& rhs)
{
	this->id = rhs.id;
	this->solid = rhs.solid;
	this->sprite = rhs.sprite;

	return *this;
}