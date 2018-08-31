#include "stdafx.h"
#include "GLScene.h"
#include "GLFramework.h"

using namespace std;

/* SCENES */
#include "Scene01_Main.h"
/*--------*/

GLFramework::GLFramework(std::string strWinTitle)
{
	m_WinTitle = strWinTitle;
}

GLFramework::~GLFramework()
{
}

void GLFramework::init(int argc, char * argv[], int WinWidth, int WinHeight, int DisplayMode)
{
	m_Timer.reset();
	glutInit(&argc, argv);
	glutInitDisplayMode(DisplayMode);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WinWidth) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - WinHeight) / 2);
	glutCreateWindow(m_WinTitle.c_str());

	m_Framework = this;
	//glutFullScreen();

	glewInit();
	glEnable(GL_DEPTH_TEST);

	addScene("Main", new S01Main, true);
}

void GLFramework::run()
{
	glutMainLoop();
}

void GLFramework::draw()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	render();

	glutSwapBuffers();
}

void GLFramework::render()
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->render();
}

void GLFramework::reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	int d = (w > h) ? w : h;
	glOrtho(0, w, h, 0, -1.f, 1.f);

	glMatrixMode(GL_MODELVIEW);
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->reshape(w, h);
	glutPostRedisplay();
}

void GLFramework::keyboardDown(unsigned char key, int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->keyboard(key, GLUT_DOWN, x, y, false);
}

void GLFramework::keyboardUp(unsigned char key, int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->keyboard(key, GLUT_UP, x, y, false);
}

void GLFramework::mouse(int button, int state, int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->mouse(button, state, x, y);
}

void GLFramework::motion(int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->motion(GLUT_DOWN, x, y);
}

void GLFramework::freeMotion(int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->motion(GLUT_UP, x, y);
}

void GLFramework::specialDown(int key, int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->keyboard(key, GLUT_DOWN, x, y, true);
}

void GLFramework::specialUp(int key, int x, int y)
{
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->keyboard(key, GLUT_UP, x, y, true);
}

void GLFramework::update(int value)
{

	m_Timer.tick();
	if (m_Scenes[m_CurrentScene])
		m_Scenes[m_CurrentScene]->update(m_Timer.getTimeElapsed());

	std::string fps_title = m_WinTitle + " - ( " + std::to_string(m_Timer.getFPS()) + " FPS )";
	glutSetWindowTitle(fps_title.c_str());
	glutPostRedisplay();
	glutTimerFunc(m_fps, fnTimer, 1);
}

void GLFramework::regDrawFunction(DrawFunc draw)
{
	fnDraw = draw;
}

void GLFramework::regReshapeFunction(ReshapeFunc reshape)
{
	fnReshape = reshape;
}

void GLFramework::regTimerFunction(TimerFunc timer)
{
	fnTimer = timer;
}

void GLFramework::regKeyboardFunction(KeyboardFunc keyboardDown, KeyboardFunc keyboardUp)
{
	fnKeyboardDown = keyboardDown;
	fnKeyboardUp = keyboardUp;
}

void GLFramework::regMouseFunction(MouseFunc mouse)
{
	fnMouse = mouse;
}

void GLFramework::regMotionFunction(MotionFunc motion, MotionFunc freeMotion)
{
	fnMotion = motion;
	fnFreeMotion = freeMotion;
}

void GLFramework::regSpecialFunction(SpecialFunc specialDown, SpecialFunc specialUp)
{
	fnSpecialDown = specialDown;
	fnSpecialUp = specialUp;
}

void GLFramework::bindGLFunctions()
{
	glutDisplayFunc(fnDraw);
	glutReshapeFunc(fnReshape);
	glutKeyboardFunc(fnKeyboardDown);
	glutKeyboardUpFunc(fnKeyboardUp);
	glutMouseFunc(fnMouse);
	glutMotionFunc(fnMotion);
	glutPassiveMotionFunc(fnFreeMotion);
	glutSpecialFunc(fnSpecialDown);
	glutSpecialUpFunc(fnSpecialUp);
	glutTimerFunc(m_fps, fnTimer, 1);
}

void GLFramework::addScene(std::string strSceneName, GLScene * pScene, bool bMakeThisCurrentScene)
{
	if (!pScene) return;
	pScene->init();
	pScene->reset();
	m_Scenes.emplace(strSceneName, pScene);
	if (bMakeThisCurrentScene)
		m_CurrentScene = strSceneName;
}

void GLFramework::popScene()
{
	m_Scenes.erase(m_CurrentScene);
}

void GLFramework::deleteScenes()
{
	for (auto& pScene : m_Scenes)
		if (pScene.second)
		{
			delete pScene.second;
			pScene.second = nullptr;
		}
}

void GLFramework::toScene(std::string sceneName)
{
	assert(m_Scenes.find(sceneName) != m_Scenes.end());
	m_CurrentScene = sceneName;
	m_Scenes[m_CurrentScene]->reset();
}