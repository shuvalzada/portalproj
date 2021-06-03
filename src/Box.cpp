#include "Box.h"

Box::Box(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world)
	:FixedObject(index, loc, objSize, texture, world)
{
}
