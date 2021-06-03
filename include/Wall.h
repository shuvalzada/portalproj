#pragma once
#include "Player.h"
#include "UnFixedObject.h"
#include "Box.h"
class TimePresent;
class Player;
//class Box;
class Lazer;
class Acid;
class Elevator;
class Trampoline;
class Button;

class Wall :public UnfixedObject
{
public:
    Wall(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void handleCollision(GameObject& gameObject) override
    {
        if (&gameObject == this) return;
        gameObject.handleCollision(*this);
    }

    void handleCollision(Player& gameObject) override {
        if (m_enterport) 
            gameObject.handlePort();
        if (m_enterport || m_exitport){
            m_sprite = save;
            m_enterport = m_exitport = false;
        }
    }
    void handleCollision(Wall& gameObject) override {}
    void handleCollision(Box& gameObject) override {
        std::cout << "get" << std::endl; 
        if (m_enterport)
            gameObject.handlePort();
       if (m_enterport || m_exitport) {
           m_sprite = save;
            m_enterport = m_exitport = false;
        }
    }
    void handleCollision(Lazer&) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {}
    void handleCollision(Elevator& gameObject) override {}
    void handleCollision(Button& gameObject) override {}
    void handleCollision(Trampoline& gameObject) override {}
    void handleCollision(TimePresent& gameObject) override {}
    void handlePress(Player& gameObject) override {
        std::pair<bool, bool> port = gameObject.port(m_sprite);
        m_exitport = port.first;
        m_enterport = port.second;
        if (m_exitport) 
            m_sprite.setTexture(m_exit);
        
        else if (m_enterport) 
            m_sprite.setTexture(m_enter);
        
    }
private:
    bool m_enterport = false, m_exitport = false;
    sf::Texture m_enter, m_exit; 
    sf::Sprite save;
};