#include "../include/text_button.hpp"

void Text_Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(button_text);
}