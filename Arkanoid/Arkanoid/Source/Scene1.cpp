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

	redBlock.PushBack({ 0, 8, 16, 8 });
	redBlock.loop = false;
	redBlock.speed = 1.0f;

	yellowBlock.PushBack({ 48, 8, 16, 8 });
	yellowBlock.loop = false;
	yellowBlock.speed = 1.0f;

	blueBlock.PushBack({ 16, 8, 16, 8 });
	blueBlock.loop = false;
	blueBlock.speed = 1.0f;

	pinkBlock.PushBack({ 32, 8, 16, 8 });
	pinkBlock.loop = false;
	pinkBlock.speed = 1.0f;

	greenBlock.PushBack({ 48, 0, 16, 8 });
	greenBlock.loop = false;
	greenBlock.speed = 1.0f;
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
	App->player->Enable();
	App->ball->Enable();

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
	
	for (int i = 0; i < 13; i++) {
		if (App->tileset->getTileLevel(7, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK2 && App->tileset->getTileLevel(7, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK2)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 56, &(greyBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(7, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(7, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 56, &(greyBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(8, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(8, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 64, &(redBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(9, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(9, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 72, &(yellowBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(10, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(10, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 80, &(blueBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(11, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(11, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 88, &(pinkBlock.GetCurrentFrame()), 1.0f);
		}
		if (App->tileset->getTileLevel(12, 1 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(12, 2 + (2 * i)).id == ModuleTileset::TileType::HITBLOCK1)
		{
			App->render->Blit(fgTexture, 8 + (16 * i), 96, &(greenBlock.GetCurrentFrame()), 1.0f);
		}
	}
	//App->render->Blit(fgTexture, 8, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 24, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 40, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 56, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 72, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 88, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 104, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 120, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 136, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 152, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 168, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 184, 56, &(greyBlock.GetCurrentFrame()), 1.0f);
	//App->render->Blit(fgTexture, 200, 56, &(greyBlock.GetCurrentFrame()), 1.0f);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp()
{

	return true;
}