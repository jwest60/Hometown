#include <fstream>
#include <iostream>

#include "animation_handler.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

Animation_Handler::Animation_Handler() : frame_height(32), frame_width(16), playing(false), t(0)
{
	this->current_frame = sf::IntRect(0, 0, this->frame_width, this->frame_height);
	this->current_anim = Animation(this->current_frame, "", 1, 0);
}

Animation_Handler::Animation_Handler(sf::Texture& sheet, const std::string& atlas_name) : frame_height(32), frame_width(16)
{

}

// split a spritesheet into animations
void Animation_Handler::create_animations(const sf::Texture& sprite, const std::string& atlas_name)
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

		unsigned int left = it->find("left").value();
		unsigned int top = it->find("top").value();
		unsigned int width = it->find("width").value();
		unsigned int height = it->find("height").value();
		unsigned int frames = it->find("frames").value();

		sf::IntRect rect(left, top, width, height);

		Animation anim(rect, name, frames, 0.2);

		animations[it.key()] = anim;
	}

	return;
}

void Animation_Handler::update_frame(const float dt)
{
	if (!playing) return;

	float duration = this->current_anim.duration;

	int frame = int((t + dt) / duration);

	if (frame > int(t / duration))
	{
		frame %= this->current_anim.frames;

		this->current_frame.left = current_frame.width * frame;
	}

	this->t += dt;
	this->t = this->t > duration * this->current_anim.frames ? 0.0f : this->t;

	return;
}

void Animation_Handler::set_animation(const std::string& name)
{
	std::map<std::string, Animation>::iterator it = this->animations.find(name);
	if (it == animations.end())
	{
		std::cerr << "WARNING: No such animation exists " << name << std::endl;

		return;
	}

	this->current_anim = animations[name];
	this->current_frame.top = this->current_anim.strip.top;
}

Animation& Animation_Handler::get_current_animation()
{
	return this->current_anim;
}

sf::IntRect& Animation_Handler::get_current_frame()
{
	return this->current_frame;
}

void Animation_Handler::play() { playing = true; }
void Animation_Handler::stop()
{
	this->current_frame.left = 0;
	playing = false;
}

