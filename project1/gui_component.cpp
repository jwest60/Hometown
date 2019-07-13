#include "gui_component.h"

#include <iostream>

void Gui_Component::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(this->sprite, states);
}

void Gui_Component::set_texture(sf::Texture& tex)
{
	this->sprite.setTexture(tex);
}

sf::Vector2f Gui_Component::get_size()
{
	auto rect = this->sprite.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}