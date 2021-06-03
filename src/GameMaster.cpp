#include "GameMaster.h"

GameMaster::GameMaster() : 
	m_window(sf::VideoMode(1000, 700), "Portal")
{
	Singleton& p2Sin = Singleton::getInstance();
	m_menu.runMenu(m_window);
	m_backGround.setTexture(*p2Sin.getTexture(12),true);
}

void GameMaster::run()
{
	Board board;
	b2Vec2 gravity(0.0f, 200.0f);
	b2World world(gravity);
	world.SetAllowSleeping(true);
	m_player = board.begin(world);
	bool stayInFirstLevel = false;	// DONT FORGET TO DELETE

	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	auto worldStepCounter = 60;

	m_window.setFramerateLimit(60);

	while (m_window.isOpen() && !board.end()) {
		world.Step(timeStep, 8, 3);
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			if (event.type == sf::Event::KeyPressed) {
				m_player->move(event.key.code);
			}
			if (event.type == sf::Event::MouseMoved) {
				m_player->rotateToMouse(m_window);
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				m_player->handelPressed(m_window);
			}
			board.handleCollisions(*m_player);
		}
	
		m_window.clear();
		m_window.draw(m_backGround);
		board.draw(m_window);
		m_window.display();

	}
}
