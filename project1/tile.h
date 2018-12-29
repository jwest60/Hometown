#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

enum class ID
{
	grass
};

class Tile : public sf::Drawable
{
public:

	Tile() : tile_size(1) {}

	Tile(ID id, const sf::Texture& tex, const sf::IntRect& tex_rect, unsigned int tile_size, bool solid);

	ID id;

	bool solid;

	const unsigned int tile_size;

	sf::Sprite sprite;

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};