#pragma once
#include "Menu.h"
#include "File.h"
#include "Player.h"
#include "Acid.h"
#include "Lazer.h"
#include "Box.h"
#include "Button.h"
#include "Elevator.h"
#include "TimePresent.h"
#include "Trampoline.h"
#include "Wall.h"
#include "Singleton.h"
#include "Board.h"

class GameMaster {
public:
	GameMaster();
	void run();
	enum class Objects {
		AIR = ' ', PLAYER = 'P', TIME_PRESENT = 'W', WALL = '#', BOX = 'B',
		ACID = 'A', ELEVATOR = 'E', BUTTON = 'O', TRAMPOLINE = 'T',
		LAZER = 'L',
	};

private:
	
	sf::RenderWindow m_window;
	Menu m_menu;
	sf::Sprite m_backGround;
	std::shared_ptr<Player> m_player;

};