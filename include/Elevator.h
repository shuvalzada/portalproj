#pragma once
#include "GameObject.h"
#include "UnfixedObject.h"
class Wall;
class Player;
class Box;
class Lazer;
class Acid;
class Button;
class Trampoline;
class TimePresent;

class Elevator :public UnfixedObject
{
public:
    Elevator(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void handleCollision(GameObject& gameObject) override
    {
        if (&gameObject == this) return;
        gameObject.handleCollision(*this);
    }

    void handleCollision(Player& gameObject) override {
        //go up and next level
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