#pragma once
#include "GameObject.h"
#include "UnfixedObject.h"

class Lazer : public UnfixedObject {
public:
	Lazer(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void handleCollision(GameObject& gameObject)  override {/*ignore*/ }
    void handleCollision(Player& gameObject)  override {/*ignore*/ }
    void handleCollision(Wall& gameObject)  override {/*ignore*/ }
    void handleCollision(Box& gameObject)  override {/*ignore*/ }
    void handleCollision(Lazer&) override {/*ignore*/ }
    void handleCollision(Acid& gameObject)  override {/*ignore*/ }
    void handleCollision(Elevator& gameObject)  override {/*ignore*/ }
    void handleCollision(Button& gameObject)  override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject)  override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject)  override {/*ignore*/ }
    virtual void handlePress(Player& gameObject)  override {/*ignore*/ }
    
private:

};