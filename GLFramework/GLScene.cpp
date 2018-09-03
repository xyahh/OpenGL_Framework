#include "stdafx.h"
#include "GLScene.h"
#include "GLFramework.h"

GLFramework * m_Framework = nullptr;

void GLScene::print(std::string str, float x, float y, float z)
{
	glPushMatrix();
	float sz = static_cast<float>(str.size());
	glRasterPos3f(x - sz*(5.f / 6.f), y, z);
	for (size_t s = 0; s < str.size(); s++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[s]);
	glPopMatrix();
}
