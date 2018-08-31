#pragma once

class Sound
{

public:

	Sound();
	~Sound();

	int addSound(LPCSTR path, bool isBGM = false);

	void startEffect(size_t idx);
	void startMusic(size_t idx);

	void play();
	void pause();
	void stop(bool master_stop);

	void fadeOut(int samples);
	bool playing() const;

private:
	std::vector<FMOD::Sound*>		m_Sounds;
	unsigned long long				m_ParentClock;

	int								m_initSoundsCapacity{ 30 };
	int								m_SoundsIdx{ -1 };
	bool							m_isPaused{ true };
	FMOD::DSP*						m_DSP{ nullptr };
	FMOD::System*					m_SoundSystem{ nullptr };
	FMOD::Channel*					m_SoundChannel{ nullptr };
};