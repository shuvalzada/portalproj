#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "box2d/box2d.h"

class Player;
class Wall;
class Box ; 
class Lazer;
class Acid;
class Elevator ;
class Button;
class Trampoline ;
class TimePresent;

class GameObject
{
public:
    GameObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world , const bool &dynamic);
    bool checkCollision(sf::FloatRect rec) const;
    bool isDisposed() const;
    sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderWindow&);
    virtual ~GameObject() = default;
    virtual void handleCollision(GameObject&) = 0;
    virtual void handlePress(Player& gameObject) = 0;
    virtual void handleCollision(Player&) = 0;
    virtual void handleCollision(Wall&) = 0;
    virtual void handleCollision(Box&) = 0;
    virtual void handleCollision(Lazer&) = 0;
    virtual void handleCollision(Acid&) = 0;
    virtual void handleCollision(Elevator&) = 0;
    virtual void handleCollision(Button&) = 0;
    virtual void handleCollision(Trampoline&) = 0;
    virtual void handleCollision(TimePresent&) = 0;
    virtual void jump () = 0;
    b2Vec2 getPosition();

protected:
    bool m_isDisposed = false;
    sf::Sprite m_sprite;  
    b2Body* m_body = nullptr;
    b2FixtureDef* m_fixtureDef = nullptr;
    b2World* m_world;
    
private:
    void updateSprite(const sf::Vector2f&, const sf::Vector2f& objSize);
};