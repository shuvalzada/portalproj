#pragma once
#include "FixedObject.h"
#include "Player.h"
class Wall;
class Lazer;
class Acid;
class Elevator;
class Button;
class Trampoline;
class TimePresent;

class Box :public FixedObject
{
public:
    Box(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void handleCollision(GameObject& gameObject) override
    {
        if (&gameObject == this) return;
        gameObject.handleCollision(*this);
    }

    void handleCollision(Player& gameObject) override {}
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Lazer&) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handlePress(Player& gameObject) override {
        gameObject.box(*m_body , m_sprite);
        m_body->SetTransform(b2Vec2{ m_sprite.getPosition().x, m_sprite.getPosition().y }, m_body->GetAngle());
    }

private:
};