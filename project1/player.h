#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Sprite sprite) : sprite(sprite) {}
	sf::Sprite sprite;

	void draw();
};