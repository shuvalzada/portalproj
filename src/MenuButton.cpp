#include "MenuButton.h"

MenuButton::MenuButton(const sf::Vector2f& position, const std::string& text)
{
	Singleton& p2Sin = Singleton::getInstance();
	m_buttonPosMusic.setBuffer(*p2Sin.getSund(0));
	m_text = sf::Text{text, *p2Sin.getFont() };
	m_text.setPosition(position);
	m_text.setCharacterSize(40);
	m_textRec = m_text.getGlobalBounds();
}

void MenuButton::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}

bool MenuButton::contains(sf::RenderWindow& window)
{
	if (m_textRec.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
	{
		m_text.setColor(sf::Color::Red);
		m_text.setCharacterSize(50);
		if (m_play)
			m_buttonPosMusic.play();
		m_play = false;
		return true;
	}
	else
	{
		m_text.setColor(sf::Color::White);
		m_text.setCharacterSize(40);
		m_play = true;
		return false;
	}
}