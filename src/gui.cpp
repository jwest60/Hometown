#include "../include/gui.hpp"

Gui::Gui() : gui_scale(1.0f) {}

sf::View& Gui::get_view() { return this->view; }

void Gui::set_font(sf::Font* font) { this->font = font; }

void Gui::set_view_size(const sf::Vector2u& size)
{
	sf::Vector2f size_f(size.x, size.y);

	this->view.setSize(size_f);
	this->view.setCenter(size_f * 0.5f);
}

void Gui::add_component(const std::string& name, std::unique_ptr<Gui_Component> component)
{
	// this->components.insert(std::make_pair(name, component));
}

/*
void Gui::render_component(const std::string& component, sf::Texture& tex)
{
	try
	{
		this->components[component]->set_texture(tex);
		this->components[component]->set_font(this->font);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to set texture of component because component does not exist: " << component << std::endl;
	}

	return;
}
*/

void Gui::set_scale(const float scalar)
{
	this->transform_components(scalar);
}

void Gui::transform_components(const float scalar)
{
	for (auto it = this->components.begin(); it != this->components.end(); ++it)
	{
		auto& component = it->second;

		component->setScale(scalar, scalar);
		// this->center_component(*component);
	}
}

/*
void Gui::center_component(Gui_Component& component)
{
	sf::Vector2f view_center = this->view.getCenter();
	sf::Vector2f component_size = component.get_size();
	sf::Vector2f component_scale = component.getScale();
	float x = view_center.x - (component_size.x * component_scale.x * 0.5f);
	float y = view_center.y - (component_size.y * component_scale.y * 0.5f);
	component.setPosition(x, y);
	component.set_gui_positions();
}
*/

void Gui::show_component(const std::string& component)
{
	try
	{
		this->components[component]->set_visible(true);
		this->draw_stack.push_back(this->components[component].get());
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to set visibility of component because component does not exist: " << component << std::endl;
	}
}

void Gui::hide_component(const std::string& component)
{
	try
	{
		this->components[component]->set_visible(false);
		if (!this->draw_stack.empty()) this->draw_stack.pop_back();
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to set visibility of component because component does not exist: " << component << std::endl;
	}
}

void Gui::toggle_component_visibility(const std::string& component)
{
	try
	{
		this->components[component]->is_visible() ? hide_component(component) : show_component(component);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "warning: failed to set visibility of component because component does not exist: " << component << std::endl;
	}
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto component : this->draw_stack)
		if (component->is_visible()) target.draw(*component);
}

void Gui::handle_input(const sf::Vector2i& mouse_pos)
{
	for (auto component : this->draw_stack)
		if (component->is_visible()) component->handle_input(mouse_pos);
}

void Gui::handle_event(const sf::Vector2i& mouse_pos, const sf::Event& event)
{
	for (auto component : this->draw_stack)
		if (component->is_visible()) component->handle_event(mouse_pos, event);
}