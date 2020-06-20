#pragma once

#include "Globals.h"
#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModuleTileset.h"
#include "SceneIntro.h"
#include "Scene1.h"

#define NUM_MODULES 12

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModuleRender;
class SceneLevel1;
class ModuleCollisions;
class ModuleFonts;
class ModulePlayer;
class ModuleTileset;
class ModuleFadeToBlack;
class SceneIntro;

class Application {
public:

	Application();

	~Application();

	bool Init();

	update_status Update();

	bool CleanUp();

public:
	Module* modules[NUM_MODULES];

	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModuleAudio* audio = nullptr;

	ModulePlayer* player = nullptr;
	ModuleTileset* tileset = nullptr;
	ModuleCollisions* collisions = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	ModuleFonts* fonts = nullptr;
	SceneIntro* intro = nullptr;

	SceneLevel1* scene1 = nullptr;

	ModuleRender* render = nullptr;

};


extern Application* App;