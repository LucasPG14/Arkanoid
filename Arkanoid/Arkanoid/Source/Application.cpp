#include "Application.h"

Application::Application() 
{
	modules[0] = window = new ModuleWindow(true);
	modules[1] = input = new ModuleInput(true);
	modules[2] = textures = new ModuleTextures(true);
	modules[3] = audio = new ModuleAudio(true);


	modules[4] = intro = new SceneIntro(true);
	modules[5] = scene1 = new SceneLevel1(false);

	modules[6] = player = new ModulePlayer(false);
	modules[7] = tileset = new ModuleTileset(false);

	modules[8] = collisions = new ModuleCollisions(true);
	modules[9] = fade = new ModuleFadeToBlack(true);
	modules[10] = fonts = new ModuleFonts(true);
	modules[11] = render = new ModuleRender(true);
}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	for (int i = 0; i < NUM_MODULES && ret; ++i)
	{
		ret = modules[i]->Init();
	}

	for (int i = 0; i < NUM_MODULES && ret; i++) {
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	}

	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : update_status::UPDATE_CONTINUE;
	}

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : update_status::UPDATE_CONTINUE;
	}

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : update_status::UPDATE_CONTINUE;
	}

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;
	}

	return ret;
}
