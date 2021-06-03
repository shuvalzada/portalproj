#pragma once

#include "MenuButton.h"


class Menu {
public:
	Menu() = default;
	void runMenu(sf::RenderWindow& window);
	// check the reless of the button on the mnue
	bool checkReleased(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	void checkMousOn(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);

private:
	void music();
	void startWindow(sf::RenderWindow& window);
	void startMusic();
	void draw(sf::RenderWindow& window);

	std::vector <sf::Texture> m_texture;
	std::vector<MenuButton> m_buttonsMenu;
	sf::Music m_music;
	sf::Sprite m_sprite;
	bool musicIsOn = true;
};