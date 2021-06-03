#pragma once
#include "FixedObject.h"
#include "Animation.h"
#include "Singleton.h"
class Wall;
class Box ; 
class Lazer;
class Acid;
class Elevator ;
class Button;
class Trampoline ;
class TimePresent;

class Player :public FixedObject
{
public:
    using FixedObject::FixedObject;
    void move(sf::Keyboard::Key key);
    void draw(sf::RenderWindow&) override;
    Player(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, 
        const sf::Texture& texture, b2World& world , std::vector<std::shared_ptr<GameObject>>);

    void handleCollision(GameObject& gameObject) override
    {     
        if (&gameObject == this) return;
            gameObject.handleCollision(*this);
    }
    void handelPressed(sf::RenderWindow& window);
    void handleCollision(Player& gameObject) override { std::cout << "player" << std::endl; };
    void handleCollision(Wall& gameObject) override { std::cout << "wall" << std::endl; };
    void handleCollision(Box& gameObject) override { std::cout << "box" << std::endl; };
    void handleCollision(Lazer&) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override { std::cout << "acid" << std::endl; };
    void handleCollision(Elevator& gameObject) override { std::cout << "elevator" << std::endl; };
    void handleCollision(Button& gameObject) override { std::cout << "button" << std::endl; };
    void handleCollision(Trampoline& gameObject) override { std::cout << "trampoline" << std::endl; };
    void handleCollision(TimePresent& gameObject) override { std::cout << "time present" << std::endl; };
    void handlePress(Player& gameObject) override {}
    void rotateToMouse(sf::RenderWindow& window);
    void box(b2Body& box, const sf::Sprite& sprite);
    void jump()override;
   

private:
    Animation m_animation;
    sf::Texture m_gunTexture, m_mouseTexture;
    sf::Sprite m_gunSprite , m_mouseSprite;
    int direction = 1;
    bool firstr = true, firstl = true, moved = false; //, m_enter = false, m_exit = false;
    std::vector<std::shared_ptr<GameObject>> m_objects;
    b2Body* m_box = nullptr;
  //  sf::Vector2f m_exitloc;

};