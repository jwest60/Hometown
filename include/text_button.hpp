#pragma once

#include "button.hpp"

class Text_Button : public Button
{
public:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::Text button_text;

	sf::Font *font;
};