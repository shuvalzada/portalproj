#pragma once

#include "Player.h"
#include "UnfixedObject.h"

class Wall;
class Player;
class Box;
class Lazer;
class Acid;
class Elevator;
class TimePresent;
class Button;

class Trampoline :public UnfixedObject
{
public:
    Trampoline(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void handleCollision(GameObject& gameObject) override
    {
        if (&gameObject == this) return;
        gameObject.handleCollision(*this);
    }
    
    void handleCollision(Player& gameObject) override {
        if (m_sprite.getPosition().y - gameObject.getPosition().y > 0 &&
            m_sprite.getPosition().y - gameObject.getPosition().y < 100 && 
            abs(m_sprite.getPosition().x - gameObject.getPosition().x) < 100)
             gameObject.jump();
    }
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Lazer&) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handlePress(Player& gameObject) override {}

private:

};