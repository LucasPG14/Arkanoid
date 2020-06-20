#include "SceneIntro.h"

#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"

#include "ModuleCollisions.h"
//#include "ModuleEnemies.h"


#include <SDL\include\SDL_scancode.h>
#include <SDL\include\SDL.h>
#include <SDL_mixer\include\SDL_mixer.h>

#include <stdio.h>


SceneIntro::SceneIntro(bool startEnabled) : Module(startEnabled)
{

}

SceneIntro::~SceneIntro()
{

}

// Load assets
bool SceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	

	return ret;
}

update_status SceneIntro::Update()
{
	if (App->input->keys[SDL_SCANCODE_RETURN] == Key_State::KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->scene1, 30);
	}
	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneIntro::PostUpdate()
{


	return update_status::UPDATE_CONTINUE;
}

bool SceneIntro::CleanUp()
{


	return true;
}