#include "File.h"

//add to the readme file the format of the level file - name + ingredients
File::File()
	:m_col(0), m_row(0)
{
}

std::pair<std::vector <char>, std::vector <sf::Vector2f>> File::readLevel(const int& index)
{
	openFile(index);
	std::pair<std::vector <char>, std::vector <sf::Vector2f>>  map;
	char type;
	std::string rowsInput;
	std::string colsInput;

	// Get the size of the map
	m_file >> rowsInput >> colsInput;
	m_row = stoi(rowsInput);
	m_col = stoi(colsInput);
	auto objctWidth = ((double)1000 / m_col);
	auto objctHeight = ((double)700 / m_row);
	m_file.get();

	// Build the map
	for (auto i = 0; i < m_row; i++) {
		for (auto j = 0; j < m_col; j++) {
			m_file.get(type);
			charIsValid(type);
			map.first.push_back(type);
			sf::Vector2f loc = { (float)(j * objctWidth),(float)(i * objctHeight) };
			map.second.push_back(loc);
			type = ' ';
		}
		m_file.get();
	}
	m_file.get();

	if (m_file.eof())
		m_file.close();

	return map;
}

int File::getRow() const
{
	return m_row;
}

int File::getCol() const
{
	return m_col;
}

void File::openFile(const int& index)
{
	std::string fileName = "level_";
	fileName.append(std::to_string(index));
	fileName.append(".txt");

	m_file.open(fileName);

	if (!m_file.is_open())
		throw std::exception("Cannot Open File");
}

bool File::charIsValid(const char& obj) const
{
	if (obj == 'p')
		return true;
	if (obj == 'P' ||
		obj == 'W' ||
		obj == '#' ||
		obj == 'B' ||
		obj == 'A' ||
		obj == 'E' ||
		obj == 'O' ||
		obj == ' ' ||
		obj == 'T' ||
		obj == 'G' ||
		obj == 'M')
		return true;

	throw  std::invalid_argument("One of the inputs invalid");
}
