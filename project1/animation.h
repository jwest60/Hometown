#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// holds a strip and information about how the strip should be played
struct Animation
{
	Animation() : frames(0), duration(0) {}

	Animation(sf::IntRect strip, std::string name, float duration) : strip(strip), name(name), duration(duration) {}

	sf::IntRect strip;

	// human-readable name for the animation
	std::string name;

	// number of frames in the strip
	int frames;

	// the number of frames each animation plays for
	float duration;
};



