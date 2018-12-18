#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "animation.h"

class Animation_Handler
{
public:

	Animation_Handler() {}
	Animation_Handler(sf::Sprite& sheet, const std::string& atlas_name);

	void create_animations(const sf::Sprite& sprite, const std::string& atlas_name);
	void set_animation(const std::string& name);

	sf::IntRect get_animation() { return current_frame; }

private:

	std::map<std::string, Animation> animations;

	sf::IntRect current_frame;
	Animation current_anim;

	int frame_width;
	int frame_height;
};