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

	m_Camera.setDistance(2000.f);
	m_Camera.setPerspective(30.f, 0.125f, 3500.f);
	m_Camera.setSensitivity(10.f);

	m_Model.load("Resources/model.obj", "Resources/texture.png");

	for (int i = 0; i < 10; ++i)
	{
		m_Object[i].setModel(&m_Model);
		m_Object[i].setPosition(i*200.f - 1000.f, 0.f, 0.f);
	}

}

void S01Main::reset()
{
}

void S01Main::render()
{
	m_Camera.ready();
	for (int i = 0; i < 10; ++i)
		m_Object[i].render();
}

void S01Main::reshape(int w, int h)
{

}

void S01Main::keyboard(int key, bool pressed, int x, int y, bool special)
{

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
