#include "Scene1.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

#include "ModuleTileset.h"

SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled)
{
	greyBlock.PushBack({ 0, 16, 16, 8 });
	greyBlock.loop = false;
	greyBlock.speed = 1.0f;
}

SceneLevel1::~SceneLevel1()
{

}

// Load assets
bool SceneLevel1::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Backgrounds/Backgrounds.png");

	fgTexture = App->textures->Load("Assets/Blocks/Blocks.png");

	App->tileset->Enable();

	return ret;
}

update_status SceneLevel1::Update()
{


	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLevel1::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 16, NULL);
	
	App->render->Blit(fgTexture, 8, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 24, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 40, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 56, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 72, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 88, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 104, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 120, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 136, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 152, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 168, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 184, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	App->render->Blit(fgTexture, 200, 56, &(greyBlock.GetCurrentFrame()), 1.0f);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp()
{

	return true;
}