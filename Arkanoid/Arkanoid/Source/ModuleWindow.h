#pragma once

#include "Module.h"


struct SDL_Window;
struct SDL_Surface;

class ModuleWindow : public Module
{
public:
	ModuleWindow(bool startEnabled);

	~ModuleWindow();

	bool Init() override;


	bool CleanUp() override;

public:

	SDL_Window* window = nullptr;

	SDL_Surface* screenSurface = nullptr;
};