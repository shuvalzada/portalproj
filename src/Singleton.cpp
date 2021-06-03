#include "Singleton.h"

std::vector<sf::Texture> Singleton::m_textures;
std::vector<sf::Texture*> Singleton::m_tempTexCpy;
std::vector<sf::Font> Singleton::m_fonts;
std::vector<sf::Font*> Singleton::m_tempFontCpy;
std::vector<sf::SoundBuffer> Singleton::m_soundBuffers;
std::vector<sf::SoundBuffer*> Singleton::m_tempSoundCpy;

Singleton& Singleton::getInstance()
{
	static Singleton instance;
	return instance;
}

sf::Texture* Singleton::getTexture(const int& index) const
{
	sf::Texture* p2Texture = new sf::Texture(m_textures[index]);
	m_tempTexCpy.push_back(p2Texture);

	return p2Texture;
}

sf::Font* Singleton::getFont() const
{
	sf::Font* p2Font = new sf::Font(m_fonts[0]);
	m_tempFontCpy.push_back(p2Font);

	return p2Font;

}

sf::SoundBuffer* Singleton::getSund(const int& index)
{
	sf::SoundBuffer* p2Buffer = new sf::SoundBuffer(m_soundBuffers[index]);
	m_tempSoundCpy.push_back(p2Buffer);

	return p2Buffer;
}

Singleton::~Singleton()
{
	for (auto i = 0; i < m_tempTexCpy.size(); i++)
		delete m_tempTexCpy[i];

	for (auto i = 0; i < m_tempFontCpy.size(); i++)
		delete m_tempFontCpy[i];

	for (auto i = 0; i < m_tempSoundCpy.size(); i++)
		delete m_tempSoundCpy[i];
}

Singleton::Singleton()
{

	m_textures.resize(15);

	if (!(m_textures[0].loadFromFile("Menu.png") &&
		m_textures[1].loadFromFile("player_right1.png") &&
		m_textures[2].loadFromFile("Watch.png") &&
		m_textures[3].loadFromFile("Wall.png") &&
		m_textures[4].loadFromFile("Box.png") &&
		m_textures[5].loadFromFile("Acid.png") &&
		m_textures[6].loadFromFile("Door.png") &&
		m_textures[7].loadFromFile("Button.png") &&

		//להכניס כאן טרפולינה לייזר טו ולייזר רע
		m_textures[8].loadFromFile("Trampoline.png") &&
		m_textures[9].loadFromFile("LaserHouse.png") &&
		m_textures[10].loadFromFile("EntrancePortal.png") &&
		m_textures[11].loadFromFile("ExitPortal.png") &&
		m_textures[12].loadFromFile("BackGround.png") &&
		m_textures[13].loadFromFile("playerGun.png") &&
		m_textures[14].loadFromFile("mouseGunPic.png")))

		throw std::exception("error in load texture");

	m_fonts.resize(1);
	if (!(m_fonts[0].loadFromFile("font.ttf")))
		throw std::exception("error in load font");

	m_soundBuffers.resize(7);
	if (!(m_soundBuffers[0].loadFromFile("buttonPopMusic.wav")) &&
		m_soundBuffers[1].loadFromFile("ClockPresentMusic.wav") &&
		m_soundBuffers[2].loadFromFile("EasyGameMusic.wav") &&
		m_soundBuffers[3].loadFromFile("GameOverMusic.wav") &&
		m_soundBuffers[4].loadFromFile("HardGameMusic.wav") &&
		m_soundBuffers[5].loadFromFile("NextLevelMusic.wav") &&
		m_soundBuffers[6].loadFromFile("TrampolineMusic.wav"))
		throw std::exception("error in load sund");
}