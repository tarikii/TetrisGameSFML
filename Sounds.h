#pragma once

#include <iostream>
#include "SFML/Audio.hpp"

// Header class that deals with the music, sounds when something happens, and sound buffer
class Sounds
{
private:
	sf::Music music;
	sf::Sound lineSound;
	sf::Sound newRecordSound;
	sf::Sound gameOverSound;
	sf::SoundBuffer lineSoundBuffer;
	sf::SoundBuffer newRecordSoundBuffer;
	sf::SoundBuffer gameOverSoundBuffer;
public:
	Sounds();
	void PlayMusic();
	void PauseMusic();
	void PlayLine();
	void PlayNewRecord();
	void PlayGameOver();
};