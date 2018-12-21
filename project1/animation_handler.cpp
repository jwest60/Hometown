#include <fstream>
#include <iostream>

#include "animation_handler.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

Animation_Handler::Animation_Handler(sf::Sprite& sheet, const std::string& atlas_name)
{
	this->create_animations(sheet, atlas_name);
}

// split a spritesheet into animations
void Animation_Handler::create_animations(const sf::Sprite& sprite, const std::string& atlas_name)
{
	std::map<std::string, sf::IntRect> sprites;

	std::ifstream i;
	json j;
	i.open(atlas_name);
	if (i.fail()) { std::cerr << "warning: failed to open atlas " << atlas_name << std::endl; return; }
	i >> j;
	i.close();

	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		std::string name = it.key();
		int left = it->find("left").value();
		int top = it->find("top").value();
		int width = it->find("width").value();
		int height = it->find("height").value();

		sf::IntRect rect(left, top, width, height);

		Animation anim(rect, name, 10);

		animations[it.key()] = anim;
	}

	return;
}

void Animation_Handler::set_animation(const std::string& name)
{
	

	this->current_anim = animations[name];
}



