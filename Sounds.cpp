#include "Sounds.h"

Sounds::Sounds()
{
	music.openFromFile("resources/TetrisMusic.ogg");
	music.setLoop(true);
	music.setVolume(20);

	if (!lineSoundBuffer.loadFromFile("resources/line.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	if (!newRecordSoundBuffer.loadFromFile("resources/newRecord.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	if (!gameOverSoundBuffer.loadFromFile("resources/gameOver.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	lineSound.setBuffer(lineSoundBuffer);
	newRecordSound.setBuffer(newRecordSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

void Sounds::PlayMusic()
{
	music.play();
}

void Sounds::PauseMusic()
{
	music.pause();
}

void Sounds::PlayLine()
{
	lineSound.play();
}

void Sounds::PlayNewRecord()
{
	newRecordSound.play();
}

void Sounds::PlayGameOver()
{
	gameOverSound.play();
}