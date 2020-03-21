#include "../include/layer.hpp"

Layer::Layer(sf::View *view, const unsigned int width, const unsigned int height, const unsigned int tile_size)
	: view(view), width(width), height(height), tile_size(tile_size), visible(true)
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
	if (!this->visible) return;

	/* Find the length and width of the view */
	int start_x = (this->view->getCenter().x - (this->view->getSize().x * 0.5)) / this->tile_size;
	int end_x = (this->view->getCenter().x + (this->view->getSize().x * 0.5)) / this->tile_size;
	int start_y = (this->view->getCenter().y - (this->view->getSize().y * 0.5)) / this->tile_size;
	int end_y = (this->view->getCenter().y + (this->view->getSize().y * 0.5)) / this->tile_size;

	/* Offset the endX and endY by one tile to ensure that the view is fully covered with tiles */
	end_x++;
	end_y++;

	/* Check to make sure that the corners aren't off the map */
	if (start_x < 0)
		start_x = 0;
	if (start_x > this->width)
		start_x = this->width;

	if (end_x < 0)
		end_x = 0;
	if (end_x > this->width)
		end_x = this->width;

	if (start_y < 0)
		start_y = 0;
	if (start_y > this->height)
		start_y = this->height;

	if (end_y < 0)
		end_y = 0;
	if (end_y > this->height)
		end_y = this->height;

	std::cout << start_x << '\n';

	/* Draw all tiles within the view */
	for (int y = start_y; y < end_y; y++)
	{
		for (int x = start_x; x < end_x; x++)
		{
			if (y * this->width + x > this->tiles.size() - 1) break; // Does the tile exist?

			target.draw(this->tiles[y * this->width + x]);
		}
	}
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