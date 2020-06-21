#include "ModulePlayer.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFonts.h"

#include <stdio.h>
#include <SDL\include\SDL.h>

ModulePlayer::ModulePlayer(bool startEnabled) : Module(startEnabled)
{
	idleAnim.PushBack({ 32, 0, 32, 8 });
	idleAnim.speed = 1.0f;
	idleAnim.loop = false;

	ballAnim.PushBack({ 0, 40, 5, 4 });
}

ModulePlayer::~ModulePlayer()
{

}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");

	bool ret = true;

	texture = App->textures->Load("Assets/Player/Player.png");

	position.x = 96;
	position.y = 232;

	ballPosition.x = 109.5;
	ballPosition.y = 228;

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
	{
		position.x += speed + 0.5f;
		if (spacePressed == false) {
			ballPosition.x += speed + 0.5f;
		}
	}

	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
	{
		position.x -= speed;
		if (spacePressed == false) {
			ballPosition.x -= speed + 0.5f;
		}
	}

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		spacePressed = true;
	}

	if (spacePressed == true)
	{
		ballPosition.x += speedX;
		ballPosition.y -= speedY;
	}

	iPoint tilePlayer({ position.x / TILE_SIZE, position.y / TILE_SIZE });
	fPoint tileBall({ ballPosition.x / TILE_SIZE, ballPosition.y / TILE_SIZE });

	if (App->tileset->getTileLevel(tilePlayer.y, tilePlayer.x).id == ModuleTileset::TileType::WALL)
	{
		position.x = 8;
		if (spacePressed == false)
		{
			ballPosition.x = position.x + 13.5;
		}	
	}

	if (App->tileset->getTileLevel(tilePlayer.y, tilePlayer.x + 4).id == ModuleTileset::TileType::WALL)
	{
		position.x = 184;
		if (spacePressed == false)
		{
			ballPosition.x = position.x + 13.5;
		}
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::WALL)
	{
		speedX = -speedX;
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::WALL)
	{
		speedX = -speedX;
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::WALL && App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::WALL)
	{
		speedY = -speedY;
	}

	//if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::HITBLOCK2 && App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::HITBLOCK2)
	//{
	//	/*App->tileset->changeTile(tileBall);*/
	//}


	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	App->render->Blit(texture, position.x, position.y, &(idleAnim.GetCurrentFrame()), 1.0f);

	App->render->Blit(texture, ballPosition.x, ballPosition.y, &(ballAnim.GetCurrentFrame()), 1.0f);

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	
}