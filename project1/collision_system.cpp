#include "collision_system.h"

Collision_System::Collision_System(unsigned int width, unsigned int height, unsigned int tile_size) : width(width), height(height), tile_size(tile_size)
{
	this->collisions.resize(width * height, false);

	this->collisions[10 * this->width + 10] = true;
}

bool Collision_System::col_exists_at_point(float x, float y)
{
	unsigned int x_adj = int(x) / this->tile_size;
	unsigned int y_adj = int(y) / this->tile_size;

	unsigned int i = y_adj + (x_adj * this->width);

	return i < this->collisions.size() ? this->collisions[i] : true;
}

sf::Vector2f Collision_System::entity_adjust_position(sf::Vector2f& move, sf::FloatRect& bounds)
{
	sf::Vector2f move_adjusted = move;

	if (move.x)
	{
		if (bounds.left + move.x < 0)
		{
			move_adjusted.x = abs(bounds.left);
		}

		if (move.x > 0)
		{
			if (col_exists_at_point(bounds.left + bounds.width + move.x, bounds.top) || col_exists_at_point(bounds.left + bounds.width + move.x, bounds.top + bounds.height))
			{
				int x = int(bounds.left + bounds.width + move.x) - (int(bounds.left + bounds.width + move.x) % this->tile_size) - 1;
				move_adjusted.x = x - (bounds.left + bounds.width);
			}
		}
		else
		{
			if (col_exists_at_point(bounds.left + move.x, bounds.top) || col_exists_at_point(bounds.left + move.x, bounds.top + bounds.height))
			{
				int x = int(bounds.left + move.x) - (int(bounds.left + move.x) % this->tile_size);
				x += this->tile_size;
				move_adjusted.x = x - bounds.left;
			}
		}
	}

	if (move.y)
	{
		if (bounds.top < 0)
		{
			move_adjusted.x = abs(bounds.top);
		}

		if (move.y > 0)
		{
			if (col_exists_at_point(bounds.left, bounds.top + bounds.height + move.y) || col_exists_at_point(bounds.left + bounds.width, bounds.top + bounds.height + move.y))
			{
				int y = int(bounds.top + bounds.height + move.y) - (int(bounds.top + bounds.height + move.y) % this->tile_size) - 1;
				move_adjusted.y = y - (bounds.top + bounds.height);
			}
		}
		else
		{
			if (col_exists_at_point(bounds.left, bounds.top + move.y) || col_exists_at_point(bounds.left + bounds.width, bounds.top + move.y))
			{
				int y = int(bounds.top + move.y) - (int(bounds.top + move.y) % this->tile_size);
				y += this->tile_size;
				move_adjusted.y = y - bounds.top;
			}
		}
	}

	return move_adjusted;
}

