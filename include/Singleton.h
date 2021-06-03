#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

class Singleton
{
public:
	static Singleton& getInstance();
	sf::Texture* getTexture(const int&) const;//return the texture
	sf::Font* getFont() const;// the front for text
	sf::SoundBuffer* getSund(const int& index);

	~Singleton();

private:
	Singleton();
	static std::vector<sf::Font> m_fonts;
	static std::vector<sf::Font*> m_tempFontCpy;
	static std::vector<sf::Texture> m_textures;
	static std::vector<sf::Texture*> m_tempTexCpy;

	static std::vector<sf::SoundBuffer> m_soundBuffers;
	static std::vector<sf::SoundBuffer*> m_tempSoundCpy;
};