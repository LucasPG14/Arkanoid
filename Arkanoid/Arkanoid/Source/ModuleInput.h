#pragma once


#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_scancode.h"

#define MAX_KEYS 256

enum Key_State
{
	KEY_IDLE,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:
	ModuleInput(bool startEnabled);

	~ModuleInput();


	bool Init() override;

	update_status PreUpdate() override;

	bool CleanUp() override;

public:
	Key_State keys[MAX_KEYS] = { KEY_IDLE };
};