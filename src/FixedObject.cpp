#include "FixedObject.h"
std::pair<bool, bool> FixedObject::port(sf::Sprite& sprite)
{
	if (!(m_exit == true && m_enter == true))
	{
		if (!m_exit)
		{
			m_exit = true;
			m_exitloc = sprite.getPosition();
			return { true , false };
		}
		else {
			m_enter = true;
			return { false , true };
		}
	}
	return { false , false };
}

void FixedObject::handlePort()
{
	//if (m_exit == true && m_enter == true) {
		m_sprite.setPosition(m_exitloc);
		m_body->SetTransform(b2Vec2{ m_sprite.getPosition().x, m_sprite.getPosition().y }, m_body->GetAngle());
		m_exit = m_enter = false;
	//}
}

