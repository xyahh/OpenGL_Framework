#include "stdafx.h"
#include "Scene01_Main.h"
#include "GLFramework.h"

S01Main::S01Main()
{
}

S01Main::~S01Main()
{
}

void S01Main::init()
{
	m_SoundPlayer.selectFolder("Resources");

	m_Camera.setDistance(2000.f);
	m_Camera.setPerspective(30.f, 0.125f, 3500.f);
	m_Camera.setSensitivity(10.f);

	m_Model.load("Resources/model.obj", "Resources/texture.png");

	for (size_t i = 0; i < 10; ++i)
	{
		m_Object[i].setModel(&m_Model);
		m_Object[i].setPosition(i*200.f - 1000.f, 0.f, 0.f);
	}

}

void S01Main::reset()
{
	m_SoundPlayer.play();
}

void S01Main::render()
{
	m_Camera.ready();
	print(m_SoundPlayer.getSoundFilename(), 0, 0, 200);

	for(size_t i = 0; i<10; ++i)
		m_Object[i].render();
}

void S01Main::reshape(int w, int h)
{

}

void S01Main::keyboard(int key, bool pressed, int x, int y, bool special)
{
	if(pressed)
		switch (key)
		{
			case 'w': m_SoundPlayer.setLoop(true); break;
			case '2': m_SoundPlayer.setLoop(false); break;
			case 'e': m_SoundPlayer.unpause(); break;
			case 'q': m_SoundPlayer.pause(); break;
			case 'a': m_SoundPlayer.prev(); break;
			case 's': m_SoundPlayer.shuffle(); break;
			case 'x': m_SoundPlayer.unshuffle(); break;
			case 'd': m_SoundPlayer.next(); break;
		}
}

void S01Main::mouse(int button, bool pressed, int x, int y)
{
}

void S01Main::motion(bool pressed, int x, int y)
{
	m_Camera.rotate(x, y, pressed);
}

void S01Main::update(float fDeltaTime)
{
}
