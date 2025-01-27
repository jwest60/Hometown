#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <fstream>


class Texture_Manager
{
public:
	// create a texture from a file
	void create_texture(const std::string& name, const std::string& file_name);
	sf::Texture& get_texture(const std::string& name);
	void remove_texture(const std::string& name);

	void create_font(const std::string& name, const std::string& file_name);
	sf::Font& get_font(const std::string& name);

	Texture_Manager();

private:

	std::map<std::string, sf::Texture> textures;

	std::map<std::string, sf::Font> fonts;
};