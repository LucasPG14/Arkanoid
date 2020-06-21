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

	collider = App->collisions->AddCollider({ position.x, position.y, 32, 8 }, Collider::Type::PLAYER);

	return ret;
}

update_status ModulePlayer::Update()
{
	// Moving the player with the camera scroll
	if (App->input->keys[SDL_SCANCODE_D] == Key_State::KEY_REPEAT)
	{
		position.x += speed;
		if (App->ball->spacePressed == false) {
			App->ball->ballPosition.x += speed;
		}
	}

	if (App->input->keys[SDL_SCANCODE_A] == Key_State::KEY_REPEAT)
	{
		position.x -= speed;
		if (App->ball->spacePressed == false) {
			App->ball->ballPosition.x -= speed;
		}
	}

	iPoint tilePlayer({ position.x / TILE_SIZE, position.y / TILE_SIZE });

	if (App->tileset->getTileLevel(tilePlayer.y, tilePlayer.x).id == ModuleTileset::TileType::WALL)
	{
		position.x = 8;
		if (App->ball->spacePressed == false)
		{
			App->ball->ballPosition.x = position.x + 13.5;
		}	
	}

	if (App->tileset->getTileLevel(tilePlayer.y, tilePlayer.x + 4).id == ModuleTileset::TileType::WALL)
	{
		position.x = 184;
		if (App->ball->spacePressed == false)
		{
			App->ball->ballPosition.x = position.x + 13.5;
		}
	}

	collider->SetPos(position.x, position.y);

	return update_status::UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate()
{
	App->render->Blit(texture, position.x, position.y, &(idleAnim.GetCurrentFrame()), 1.0f);

	return update_status::UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{

}