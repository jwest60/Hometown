#include "texture_manager.h"
#include <iostream>

void Texture_Manager::create_texture(const std::string name, const std::string file_name)
{
	sf::Texture* texture = new sf::Texture;
	if (!texture->loadFromFile(file_name)) { std::cerr << "ERROR: Could not find file " << file_name << std::endl; return; }

	this->textures[name] = texture;
}

sf::Texture* Texture_Manager::get_texture(std::string name)
{
	try
	{
		return this->textures.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "ERROR: texture does not exist: " << name << std::endl;
	}

	return nullptr;
}

void Texture_Manager::remove_texture(std::string name)
{
	try
	{
		delete this->textures.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "ERROR: texture does not exist: " << name << std::endl;
	}
}

Texture_Manager::~Texture_Manager()
{
	for (std::map<std::string, sf::Texture*>::iterator it = this->textures.begin(); it != this->textures.end; ++it)
		delete it->second;
}