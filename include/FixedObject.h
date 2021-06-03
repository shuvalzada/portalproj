#pragma once
#include "GameObject.h"

class FixedObject : public GameObject
{
public:
    using GameObject::GameObject;
    FixedObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world) :
        GameObject(index, loc, objSize, texture, world, true) {};
     void jump()override{};
     std::pair<bool, bool> port(sf::Sprite& sprite);
     void handlePort();
 
private:
    //each object will have a sound when the player take him or in other cases
    sf::Sound m_buttonPosMusic;
    sf::SoundBuffer buffer;
protected:
    sf::Vector2f m_exitloc;
    bool m_enter = false, m_exit = false;
};