#include "Button.h"

Button::Button(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world)
	:UnfixedObject(index, loc, objSize, texture, world)
{
}
