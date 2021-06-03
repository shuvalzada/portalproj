#pragma once

#include "GameObject.h"

class UnfixedObject : public GameObject
{
public:
    using GameObject::GameObject;
    UnfixedObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world) :
        GameObject(index, loc, objSize, texture, world, false) {};
    void jump()override {};
  
private:
    sf::Sound m_buttonPosMusic;
    sf::SoundBuffer buffer;
protected:
    b2PolygonShape* m_shape;
    b2FixtureDef* m_fixtureDef;
};