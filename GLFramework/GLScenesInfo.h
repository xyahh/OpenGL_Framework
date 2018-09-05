#pragma once
#include "GLScene.h"
#define _SCENES_

struct GLSceneInfo
{
	std::string name;
	GLScene*	pScene;
	bool		bInitAtStart{ true };
};

/*--------------------ADD SCENES HERE--------------------*/

/*~~~~~HEADER FILES~~~~*/
#include "Scene00_Logo.h"
#include "Scene01_Main.h"

/*~~~~~~~SCENES~~~~~~~*/
const GLSceneInfo SCENES[] =
{
	{"Logo", new S00Logo, true},
	{"Main", new S01Main, false}
};

/*~~~STARTING SCENE~~~*/
const std::string STARTING_SCENE { "Logo" };

/*-------------------------------------------------------*/
