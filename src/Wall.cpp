#include "Wall.h"

Wall::Wall(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world)
	:UnfixedObject(index, loc, objSize, texture, world)
{
	m_enter.loadFromFile("enterportal.png");
	m_exit.loadFromFile("exitportal.png");
	save = m_sprite;
}
