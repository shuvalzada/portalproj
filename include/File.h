#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"
//#include "GameIterator.h"



class File {
public:
	File();
	std::pair<std::vector <char>, std::vector <sf::Vector2f>>  readLevel(const int&);
	int getRow() const;
	int getCol() const;

private:
	void openFile(const int&);
	bool charIsValid(const char&) const;
	std::ifstream m_file;
	sf::Vector2f m_size;
	int m_row, m_col;
};