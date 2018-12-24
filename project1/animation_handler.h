#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include "animation.h"

class Animation_Handler
{
public:

	float t;

	Animation_Handler();
	Animation_Handler(sf::Texture& sheet, const std::string& atlas_name);

	void create_animations(const sf::Texture& sprite, const std::string& atlas_name);
	void set_animation(const std::string& name);

	void update_frame(const float dt);

	Animation& get_current_animation();
	sf::IntRect& get_current_frame();

	sf::IntRect get_animation() { return current_frame; }

	void play();
	void stop();

	bool playing;

private:

	std::map<std::string, Animation> animations;

	sf::IntRect current_frame;
	Animation current_anim;

	const int frame_width;
	const int frame_height;
};