#include "stdafx.h"
#include "SoundPlayer.h"
#include "FolderReader.h"

bool SoundPlayer::playing()
{
	return m_SoundManager.playing();
}

std::string SoundPlayer::getSoundFilename() const
{
	return std::string();
}

std::string SoundPlayer::getSoundFilename(size_t index) const
{
	return std::string();
}

int SoundPlayer::getSoundCount() const
{
	return 0;
}

void SoundPlayer::selectFolder(std::string strFolderPath, bool isMusic)
{
	m_SoundFilenames = m_SoundFolder->readFolder(strFolderPath, "mp3");
	std::string strFullSoundFilepath;
	for (auto strSoundFilename : m_SoundFilenames)
	{
		strFullSoundFilepath = strFolderPath + "/" + strSoundFilename;
		m_SoundManager.addSound(strFullSoundFilepath.c_str(), isMusic);

	}
}

