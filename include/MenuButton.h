#pragma once
//-----------------------------
#include "Singleton.h"
class MenuButton {
public:
	MenuButton(const sf::Vector2f&, const std::string&);
	void draw(sf::RenderWindow&);
	bool contains(sf::RenderWindow&);
	
private:
	sf::Text m_text;
	sf::FloatRect m_textRec;
	sf::Sound m_buttonPosMusic;
	bool m_play = false;
};