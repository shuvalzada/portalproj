#include "Player.h"

Player::Player(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,
	const sf::Texture& texture, b2World& world, std::vector<std::shared_ptr<GameObject>>obj) :
	FixedObject(index, loc, objSize, texture, world, true), m_animation(objSize),
	m_objects(obj) {

	Singleton& p2Sin = Singleton::getInstance();

	m_gunSprite.setTexture(*p2Sin.getTexture(13), true);
	m_gunSprite.setScale(objSize.x / 5 / m_gunSprite.getLocalBounds().width * 2,
		objSize.y / 5 / m_gunSprite.getLocalBounds().height * 2);
	m_gunSprite.setOrigin(m_sprite.getOrigin());
	m_gunSprite.setPosition(sf::Vector2f(loc.x + objSize.x, loc.y + objSize.y));

	m_mouseSprite.setTexture(*p2Sin.getTexture(14), true);
	m_mouseSprite.setScale(objSize.x / 2 / m_mouseSprite.getLocalBounds().width * 2,
		objSize.y / 2 / m_mouseSprite.getLocalBounds().height * 2);
	m_mouseSprite.setOrigin(m_sprite.getOrigin());
	m_mouseSprite.setPosition(sf::Vector2f(loc.x + objSize.x, loc.y + objSize.y));
	m_mouseSprite.setColor(sf::Color(255, 255, 255, 128));
	b2MassData *MassData =  new b2MassData();
	MassData->mass = m_body->GetMass()+ 10000;// mass is the mass of the second body, which is separated from the main
	m_body->SetMassData(MassData);
};

void Player::move(sf::Keyboard::Key key) {

	b2Vec2 vel = m_body->GetLinearVelocity();
	switch (key)
	{
	case sf::Keyboard::Up:
		vel.y = -100;
		m_sprite = m_animation.move(JUMP);
		break;
	case sf::Keyboard::Down:  vel.y = 100; break;
	case sf::Keyboard::Left:
		direction = 0;
		firstr = true;
		if (firstl)
			m_gunSprite.setScale({ -m_gunSprite.getScale().x , m_gunSprite.getScale().y });
		firstl = false;
		vel.x = -100;
		m_sprite = m_animation.move(LEFT);
		break;
	case sf::Keyboard::Right:
		direction = 1;
		if (firstr && !firstl)
			m_gunSprite.setScale({ -m_gunSprite.getScale().x , m_gunSprite.getScale().y });
		firstl = true;
		firstr = false;
		vel.x = 100;
		m_sprite = m_animation.move(RIGHT);
		break;
	}

	m_body->SetLinearVelocity(vel);
}
void Player::draw(sf::RenderWindow& window) {
	
	m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	window.draw(m_sprite);
	m_gunSprite.setPosition(m_body->GetPosition().x + direction * m_sprite.getGlobalBounds().width,
		m_body->GetPosition().y);
	window.draw(m_gunSprite);
	if (moved)
		window.draw(m_mouseSprite);
	if (m_box)
		m_box->SetTransform(b2Vec2{m_sprite.getPosition().x, m_sprite.getPosition().y }, m_body->GetAngle());

}
void Player::rotateToMouse(sf::RenderWindow& window)
{
	moved = true;
	sf::Vector2f curPos = m_gunSprite.getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(window);
	m_mouseSprite.setPosition(position.x, position.y);
	const float PI = 3.14159265;
	float dx = position.x - curPos.x;
	float dy = position.y - curPos.y;
	float rotation = (atan2(dy, dx) * 180) / PI;
	if (!firstl)
		m_gunSprite.setRotation(rotation + 180);
	else
		m_gunSprite.setRotation(rotation);
}
void Player::handelPressed(sf::RenderWindow& window) {

	sf::Vector2i position = sf::Mouse::getPosition(window);

	for (auto& i : m_objects)
		if (i->getGlobalBounds().contains(position.x, position.y))
			i->handlePress(*this);
}
void Player::box(b2Body &box , const sf::Sprite &sprite) {

	if (m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()) && m_box == nullptr) 
		m_box = &box;
	else //drop the box
		m_box = nullptr;
}


void Player :: jump() {

	float impulse = -m_body->GetMass()*10000000000;
	m_body->ApplyLinearImpulse(b2Vec2(0, impulse), m_body->GetWorldCenter() , true);
}
