#include "entity.h"
#include <iostream>

Entity::Entity() :
	speed(150.f),
	width(16),
	height(32) {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}

sf::FloatRect Entity::get_entity_bounds()
{ 
	sf::FloatRect bounds = this->sprite.getGlobalBounds();

	bounds.left += this->bounding_box.left;
	bounds.top += this->bounding_box.top;

	bounds.width = this->bounding_box.width;
	bounds.height = this->bounding_box.height;

	return bounds;
}

void Entity::move(const sf::Vector2f& pos)
{
	pos.x || pos.y ? this->anim_handler.play() : this->anim_handler.stop();
	this->change_animation(pos.x, pos.y);

	this->sprite.move(pos);
}

sf::Vector2f Entity::get_movement(const float dt)
{
	int h_move = sf::Keyboard::isKeyPressed(sf::Keyboard::D) 
		- sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	int v_move = sf::Keyboard::isKeyPressed(sf::Keyboard::S) 
		- sf::Keyboard::isKeyPressed(sf::Keyboard::W);

	return sf::Vector2f(h_move * this->speed * dt, v_move * this->speed * dt);
}

void Entity::change_animation(int h_move, int v_move)
{
	if (h_move > 0)
		this->anim_handler.set_animation("right");
	if (h_move < 0)
		this->anim_handler.set_animation("left");
	if (v_move > 0)
		this->anim_handler.set_animation("down");
	if (v_move < 0)
		this->anim_handler.set_animation("up");
}

void Entity::update_sprite(const float dt)
{
	this->anim_handler.update_frame(dt);
	this->set_frame(this->anim_handler.get_current_frame());
}

void Entity::set_texture(sf::Texture& tex, const std::string& atlas_name)
{ 
	this->load_bounding_box(atlas_name);

	this->sprite.setTexture(tex);
	this->sprite.setOrigin(this->width * 0.5, this->height * 0.5);
	this->anim_handler.create_animations(tex, atlas_name);
	this->set_frame(this->anim_handler.get_current_frame());
}

void Entity::set_frame(sf::IntRect& frame) { this->sprite.setTextureRect(frame); }

void Entity::load_bounding_box(const std::string& atlas_name)
{
	std::ifstream i;
	json j;
	i.open(atlas_name);
	if (i.fail()) { std::cerr << "warning: failed to open atlas " << atlas_name << std::endl; return; }
	i >> j;
	i.close();

	for (json::iterator it = j.begin(); it != j.end(); ++it)
	{
		std::string type = it->find("type").value();

		if (type != "bbox") continue;

		unsigned int left = it->find("left").value();
		unsigned int top = it->find("top").value();
		unsigned int width = it->find("width").value();
		unsigned int height = it->find("height").value();

		this->bounding_box = sf::FloatRect(left, top, width, height);

		break;
	}
}