#pragma once
#include "Sound.h"

class FolderReader;

class SoundPlayer
{

public:

	SoundPlayer();
	SoundPlayer(std::string strFolderPath);
	~SoundPlayer();

	void selectFolder(std::string strFolderPath, bool isMusic = true);

	/* PLAYER CONTROLS ----------- */
	void play();
	void pause();
	void stop();
	void next();
	void prev();
	void setLoop(bool bLoopState);
	void shuffle();
	void setVolume(float fVolume);
	/* --------------------------- */

	bool playing();

	std::string getSoundFilename() const;
	std::string getSoundFilename(size_t index) const;
	int getSoundCount() const;

private:
	Sound							m_SoundManager;
	std::unique_ptr<FolderReader>	m_SoundFolder;
	std::list<std::string>			m_SoundFilenames;
	std::list<size_t>				m_SoundIdx;
	size_t							m_CurrentSound;

};
