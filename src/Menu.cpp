#include "Menu.h"

void Menu::runMenu(sf::RenderWindow& window)
{
	startWindow(window);
	//startMusic();

	while (true)
	{
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				return;
			case sf::Event::MouseMoved:
				if (sf::Mouse::getPosition(window).x < 0 || sf::Mouse::getPosition(window).y < 0)
					continue;
				checkMousOn(event.mouseButton, window);
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Button::Left)
					if (checkReleased(event.mouseButton, window))
						return;
				break;
			default:
				break;
			}
		}
		draw(window);
	}
}

bool Menu::checkReleased(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (m_buttonsMenu[0].contains(window))
		return true;
	
	if (m_buttonsMenu[1].contains(window))
	{
		window.close();
		return true;
	}

return false;
}

void Menu::checkMousOn(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttonsMenu.size(); i++)
		m_buttonsMenu[i].contains(window);
}

void Menu::music()
{
	if (!musicIsOn)
	{
		m_music.play();
		musicIsOn = true;
	}
	else
	{
		m_music.pause();
		musicIsOn = false;
	}
}


void Menu::startWindow(sf::RenderWindow& window)
{
	Singleton& p2Sin = Singleton::getInstance();
	m_sprite.setTexture(*p2Sin.getTexture(0), true);
	m_sprite.scale(0.7f, 0.6f);
	m_buttonsMenu.push_back(*(new MenuButton{ sf::Vector2f(50, 280), "Start Game" }));
	m_buttonsMenu.push_back(*(new MenuButton{ sf::Vector2f(50, 380), "Exit" }));
	draw(window);
	
}

void Menu::startMusic()
{
	if (!m_music.openFromFile("BackMusic.ogg"))
	{
		throw "error in loading music";
	}
	m_music.play();
	m_music.setLoop(true);
}
void Menu::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
	for (auto& i : m_buttonsMenu)
		i.draw(window);
	window.display();
}