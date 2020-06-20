#pragma once

#include "Globals.h"
#include "Module.h"
#include "ModuleWindow.h"

#define NUM_MODULES 1

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleAudio;
class ModuleRender;

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

	ModuleRender* render = nullptr;

};


extern Application* App;