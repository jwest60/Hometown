#include <iostream>

#include "texture_manager.h"

Texture_Manager::Texture_Manager()
{
	this->create_texture("undefined", "res/undefined.png");
}

void Texture_Manager::create_texture(const std::string& name, const std::string& file_name)
{
	sf::Texture texture;
	if (!texture.loadFromFile(file_name)) { std::cerr << "warning: could not find file " << file_name << std::endl; return; }

	this->textures[name] = texture;
}

sf::Texture& Texture_Manager::get_texture(const std::string& name)
{
	try
	{
		return this->textures.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to get texture because texture does not exist: " << name << std::endl;
	}

	try
	{
		return this->textures.at("undefined");
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "FATAL ERROR: could not return undefined texture for " << name << std::endl;
	}

	exit(EXIT_FAILURE);
}

void Texture_Manager::remove_texture(const std::string& name)
{
	if (name == "undefined") return;

	try
	{
		this->textures.erase(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to remove texture because texture does not exist: " << name << std::endl;
	}
}