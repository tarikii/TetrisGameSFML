#include "Sounds.h"

Sounds::Sounds()
{
	// Get the music from the folder, loop it and set the volume to 20
	music.openFromFile("resources/TetrisMusic.ogg");
	music.setLoop(true);
	music.setVolume(20);

	// Initialize and check the sound buffers for each file
	if (!lineSoundBuffer.loadFromFile("resources/line.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	if (!newRecordSoundBuffer.loadFromFile("resources/newRecord.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	if (!gameOverSoundBuffer.loadFromFile("resources/gameOver.ogg"))
		std::cout << "Error loading the sound!" << std::endl;

	// Set the buffers created from the files
	lineSound.setBuffer(lineSoundBuffer);
	newRecordSound.setBuffer(newRecordSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

// Play the music of the game
void Sounds::PlayMusic()
{
	music.play();
}

// Puase the music of the game
void Sounds::PauseMusic()
{
	music.pause();
}

// Play the sound of a line completed
void Sounds::PlayLine()
{
	lineSound.play();
}

// Play the sound of a new record
void Sounds::PlayNewRecord()
{
	newRecordSound.play();
}

// Play the sound of game over
void Sounds::PlayGameOver()
{
	gameOverSound.play();
}