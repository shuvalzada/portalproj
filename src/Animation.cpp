#include "Animation.h"
#include <iostream>
//----------CONSTRUCTOR , LOAD THE WATER SPRITE IMAGE AND HIS DETAILS----------
Animation::Animation(const sf::Vector2f& objsize) {

	for (int i = 0; i < m_direction.size(); i++) {	
			m_direction[i].first = 0;}

	load(m_playerMoveLeftTextures, m_playerMove[LEFT], PLATER_LEFT_PIC_NAMES , objsize);
	load(m_playerMoveRightTextures, m_playerMove[RIGHT], PLATER_RIGHT_PIC_NAMES , objsize);
	load(m_playerJumpTextures, m_playerMove[JUMP], PLATER_JUMP_PIC_NAMES, objsize);
}

sf::Sprite Animation::move(const int& direction) {

	//reset the other direction data
	for (int i = 0; i < m_direction.size(); i++ ) {
		if (i != direction)
		{
			m_direction[i].first = 0; 
			m_direction[i].second.restart();
		}
	}

	if (m_direction[direction].second.getElapsedTime().asSeconds() > 0.1f)
	{
		m_direction[direction].first++;
		m_direction[direction].first = m_direction[direction].first % m_playerMove[direction].size();
		m_direction[direction].second.restart();
	}
	return m_playerMove[direction][m_direction[direction].first];
}

void Animation::load(vector<unique_ptr<sf::Texture>> &texVec, vector <sf::Sprite> &spVec , 
	const std::vector <std::string> &names , const sf::Vector2f& objsize){

	for (int i = 0; i < names.size(); i++) {
		texVec.push_back(make_unique<sf::Texture>());
		texVec[i]->loadFromFile(names[i]);
		spVec.push_back(sf::Sprite());
		spVec[i].setTexture(*texVec[i]);
		spVec[i].setOrigin(spVec[i].getGlobalBounds().width / 2, spVec[i].getGlobalBounds().height / 2);
		spVec[i].setScale(objsize.x / spVec[i].getLocalBounds().width,
			objsize.y / spVec[i].getLocalBounds().height);
	}
}