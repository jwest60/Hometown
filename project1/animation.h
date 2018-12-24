#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// holds a strip and information about how the strip should be played
struct Animation
{
	Animation() : frames(0), duration(0) {}

	Animation(sf::IntRect strip, const std::string& name, unsigned int frames, float duration) 
		: strip(strip), name(name), frames(frames), duration(duration) {}

	sf::IntRect strip;

	// human-readable name for the animation
	std::string name;

	// number of frames in the strip
	unsigned int frames;

	float duration;
};



