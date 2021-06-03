#pragma once
#include "GameMaster.h"

class Board
{
public:
	Board();
	~Board();
	//displayMenu();
	std::shared_ptr<Player> begin(b2World& world);
	bool end();
	void draw(sf::RenderWindow& window);
	void createObject(const char& type, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
	void handleCollisions(GameObject& gameObject);
	void operator++();

	//	Player returnPlayer();
private:

	//sf::Sprite m_backGround;
	std::vector<std::shared_ptr<GameObject>> m_objects;
	std::shared_ptr<Player> m_player;
	File m_file;
	int currentLevel = 1;
	sf::Vector2f m_objSize;
	std::pair<std::vector <char>, std::vector <sf::Vector2f>> map;
};