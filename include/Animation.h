#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Const.h"
using namespace std;

class Animation
{
public:
	Animation(const sf::Vector2f& objsize);
	sf::Sprite move(const int &direction);
	void load(vector<unique_ptr<sf::Texture>> &texVec, vector <sf::Sprite> &spVec ,
		const std::vector <std::string> &names , const sf::Vector2f& objsize);
private:
	vector<unique_ptr<sf::Texture>> m_playerJumpTextures , m_playerMoveLeftTextures , 
		m_playerMoveRightTextures;
	vector <sf::Sprite> m_playerJumpSprites;
	vector <vector <sf::Sprite>> m_playerMove{vector <sf::Sprite>() , vector <sf::Sprite>() , 
		vector <sf::Sprite>()};
	vector<pair <int, sf::Clock>> m_direction{ pair <int , sf::Clock>(), pair <int, sf::Clock>() , 
	 pair <int, sf::Clock>()};
};
