#include <iostream>

#include "../include/texture_manager.hpp"

Texture_Manager::Texture_Manager()
{
	this->create_texture("undefined", "res/undefined.png");
}

void Texture_Manager::create_texture(const std::string& name, const std::string& file_name)
{
	sf::Texture texture;
	if (!texture.loadFromFile(file_name)) { std::cerr << "warning: could not find file " << file_name << '\n'; return; }

	this->textures[name] = texture;
}

void Texture_Manager::create_font(const std::string& name, const std::string& file_name)
{
	sf::Font font;
	if (!font.loadFromFile(file_name)) { std::cerr << "warning: could not find file " << file_name << '\n'; return; }

	this->fonts[name] = font;
}

sf::Texture& Texture_Manager::get_texture(const std::string& name)
{
	try
	{
		return this->textures.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to get texture because texture does not exist: " << name << '\n';
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

sf::Font& Texture_Manager::get_font(const std::string& name)
{
	try
	{
		return this->fonts.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to get font because font does not exist: " << name << '\n';
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