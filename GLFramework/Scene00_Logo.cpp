#include "stdafx.h"
#include "Scene00_Logo.h"
#include "GLFramework.h"

S00Logo::S00Logo()
{
}

S00Logo::~S00Logo()
{
}

void S00Logo::init()
{

	m_Camera.setDistance(200.f);
	m_Camera.setPerspective(30.f, 0.125f, 3500.f);
	m_Camera.setSensitivity(1.f);

	m_Model.load("Resources/title.obj");
	m_Title.setModel(&m_Model);
	m_Title.setPosition(0.f, 0.f, 0.f);

}

void S00Logo::reset()
{
}

void S00Logo::render()
{
	m_Camera.ready();
	m_Title.render();
}

void S00Logo::reshape(int w, int h)
{

}

void S00Logo::keyboard(int key, bool pressed, int x, int y, bool special)
{
	m_Framework->toScene("Main");
}

void S00Logo::mouse(int button, bool pressed, int x, int y)
{
}

void S00Logo::motion(bool pressed, int x, int y)
{
	m_Camera.rotate(x, y, pressed);
}

void S00Logo::update(float fDeltaTime)
{
}
