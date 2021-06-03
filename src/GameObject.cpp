#include "GameObject.h"
GameObject::GameObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world , const bool& dynamic)
    :m_world(&world)
{
    m_sprite.setTexture(texture, true);
    updateSprite(loc, objSize);
    b2BodyDef body; 
    if (dynamic)
        body.type = b2_dynamicBody;
    body.bullet = true;
    m_body = m_world->CreateBody(&body);
    b2PolygonShape bodybox;
    bodybox.SetAsBox(m_sprite.getGlobalBounds().height/2,m_sprite.getGlobalBounds().width/2);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &bodybox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3;
    m_body->CreateFixture(&fixtureDef);
    m_body->SetUserData(&m_sprite);
    m_body->SetLinearVelocity({m_world->GetGravity().x, 0});
    m_body->SetTransform(b2Vec2{ m_sprite.getPosition().x, m_sprite.getPosition().y }, m_body->GetAngle());
}
bool GameObject :: checkCollision(sf::FloatRect rec) const
{
    return (m_sprite.getGlobalBounds().intersects(rec));

}
bool GameObject::isDisposed() const {

    return m_isDisposed;
}
void GameObject :: draw(sf::RenderWindow& window) {
    m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
    window.draw(m_sprite);
}
sf::FloatRect GameObject :: getGlobalBounds() const
{
    return m_sprite.getGlobalBounds();
}

void GameObject::updateSprite(const sf::Vector2f& loc, const sf::Vector2f& objSize)
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
    m_sprite.setScale(objSize.x / m_sprite.getLocalBounds().width,
        objSize.y / m_sprite.getLocalBounds().height);
    m_sprite.setPosition(sf::Vector2f(loc.x + objSize.x / 2, loc.y + objSize.y / 2 ));
}

b2Vec2 GameObject::getPosition()
{
    return m_body->GetPosition();
}
