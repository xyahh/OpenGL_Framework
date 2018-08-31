#pragma once
#include "GLScene.h"

/* UTILITIES */
#include "Model.h"
#include "Object.h"
#include "Camera.h"
/* ------------ */

class S01Main :
	public GLScene
{
public:
	S01Main();
	virtual ~S01Main();

	virtual void init();
	virtual void reset();
	virtual void render();
	virtual void reshape(int w, int h);
	virtual void keyboard(int key, int state, int x, int y, bool special);
	virtual void mouse(int button, int state, int x, int y);
	virtual void motion(int state, int x, int y);
	virtual void update(float fDeltaTime);

private:

	Camera	m_Camera;
	Model	m_Model;
	Object	m_Object[10];
};

