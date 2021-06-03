#include "Board.h"

Board::Board():m_file(){}
Board::~Board(){}

std::shared_ptr<Player> Board::begin(b2World& world)
{
	map = m_file.readLevel(currentLevel);
	auto objctWidth = ((double)1000 / m_file.getCol());
	auto objctHeight = ((double)700 / m_file.getRow());
	m_objSize = sf::Vector2f(objctWidth, objctHeight);

	for (int i = 0; i < map.first.size(); i++)
		createObject(map.first[i], map.second[i], m_objSize, world);
	return m_player;
}

bool Board::end()
{
	if (currentLevel == 2)
		return true;
	return false;
}

void Board::draw(sf::RenderWindow& window)
{

	for (auto& obj : m_objects)
		obj->draw(window);

	m_player->draw(window);

}

void Board::createObject(const char& type, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
{
	Singleton& p2Sin = Singleton::getInstance();
	if (type == (char)GameMaster::Objects::PLAYER)
		m_player = std::make_unique<Player>(type, loc, objSize, *p2Sin.getTexture(1), world, m_objects);
	switch (type)
	{
	case (char)GameMaster::Objects::WALL:
		m_objects.push_back(std::make_unique<Wall>(type, loc, objSize, *p2Sin.getTexture(3), world));
		break;
	case (char)GameMaster::Objects::ACID:
		m_objects.push_back(std::make_unique<Acid>(type, loc, objSize, *p2Sin.getTexture(5), world));
		break;
	case (char)GameMaster::Objects::TIME_PRESENT:
		m_objects.push_back(std::make_unique<TimePresent>(type, loc, objSize, *p2Sin.getTexture(2), world));
		break;
	case (char)GameMaster::Objects::TRAMPOLINE:
		m_objects.push_back(std::make_unique<Trampoline>(type, loc, objSize, *p2Sin.getTexture(8), world));
		break;
	case (char)GameMaster::Objects::BOX:
		m_objects.push_back(std::make_unique<Box>(type, loc, objSize, *p2Sin.getTexture(4), world));
		break;
	case (char)GameMaster::Objects::BUTTON:
		m_objects.push_back(std::make_unique<Button>(type, loc, objSize, *p2Sin.getTexture(7), world));
		break;
	case (char)GameMaster::Objects::ELEVATOR:
		m_objects.push_back(std::make_unique<Elevator>(type, loc, objSize, *p2Sin.getTexture(6), world));
		break;
	case (char)GameMaster::Objects::LAZER:
		m_objects.push_back(std::make_unique<Lazer>(type, loc, objSize, *p2Sin.getTexture(9), world));
		break;
	}
}

void Board::handleCollisions(GameObject& gameObject)
{
	for (auto& objetc : m_objects)
		if (gameObject.checkCollision(objetc->getGlobalBounds()))
		{
			objetc->handleCollision(gameObject);
			gameObject.handleCollision(*objetc);
		}
}

void Board::operator++()
{
	map.first.clear();
	map.second.clear();
	map = m_file.readLevel(++currentLevel);
}






