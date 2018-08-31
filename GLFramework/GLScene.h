#pragma once

class GLFramework;

/* GLOBAL VARIABLES */
extern GLFramework*	 m_Framework;
/* ---------------- */

class GLScene
{
public:
	GLScene() {}
	virtual ~GLScene() {}
	virtual void init() {}
	virtual void reset() {}
	virtual void render() {}
	virtual void reshape(int w, int h) {}
	virtual void keyboard(int key, int state, int x, int y, bool special) {}
	virtual void mouse(int button, int state, int x, int y) {}
	virtual void motion(int x, int y, int state) {}
	virtual void update(float fDeltaTime) {}

protected:

};

