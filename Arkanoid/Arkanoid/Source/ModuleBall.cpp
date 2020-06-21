#include "ModuleBall.h"

#include "Application.h"
#include "ModuleTileset.h"
#include "ModulePlayer.h"
#include "Scene1.h"
#include "ModuleInput.h"
#include "ModuleCollisions.h"

ModuleBall::ModuleBall(bool startEnabled) : Module(startEnabled)
{
	ballAnim.PushBack({ 0, 40, 5, 4 });
}

ModuleBall::~ModuleBall()
{
}

bool ModuleBall::Start()
{
	ballCollider = App->collisions->AddCollider({ (int)ballPosition.x, (int)ballPosition.y, 5, 4 }, Collider::Type::BALL, this);

	ballPosition.x = 109.5;
	ballPosition.y = 228;

	return true;
}

update_status ModuleBall::Update()
{

	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		spacePressed = true;
	}

	if (spacePressed == true)
	{
		ballPosition.x += speedX;
		ballPosition.y -= speedY;
	}

	fPoint tileBall({ ballPosition.x / TILE_SIZE, ballPosition.y / TILE_SIZE });
	iPoint tileBall2({ (int)ballPosition.x / TILE_SIZE, (int)ballPosition.y / TILE_SIZE });

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::WALL && App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x + 1.125f).id == ModuleTileset::TileType::WALL)
	{
		speedX = -speedX;
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::WALL && App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x).id == ModuleTileset::TileType::WALL)
	{
		speedX = -speedX;
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::WALL && App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::WALL)
	{
		speedY = -speedY;
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::HITBLOCK1)
	{
		speedY = -speedY;
		App->tileset->changeTile(tileBall2, false);
	}

	if (App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x).id == ModuleTileset::TileType::HITBLOCK1 && App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x + 1.125f).id == ModuleTileset::TileType::HITBLOCK1)
	{
		speedY = -speedY;
		App->tileset->changeTile(tileBall2, true);
	}

	if (App->tileset->getTileLevel(tileBall.y, tileBall.x).id == ModuleTileset::TileType::HITBLOCK2 && App->tileset->getTileLevel(tileBall.y, tileBall.x + 1.125f).id == ModuleTileset::TileType::HITBLOCK2)
	{
		speedY = -speedY;
		App->tileset->changeTile(tileBall2, false);
	}

	if (App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x).id == ModuleTileset::TileType::HITBLOCK2 && App->tileset->getTileLevel(tileBall.y + 1.5f, tileBall.x + 1.125f).id == ModuleTileset::TileType::HITBLOCK2)
	{
		speedY = -speedY;
		App->tileset->changeTile(tileBall2, true);
	}

	ballCollider->SetPos((int)ballPosition.x, (int)ballPosition.y);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleBall::PostUpdate()
{
	App->render->Blit(App->player->texture, ballPosition.x, ballPosition.y, &(ballAnim.GetCurrentFrame()), 1.0f);

	return update_status::UPDATE_CONTINUE;
}

void ModuleBall::OnCollision(Collider* c1, Collider* c2)
{
	if (c2->type == Collider::Type::PLAYER)
	{
		if (c1->Intersects(c2->rect) == true)
		{
			speedY = -speedY;
		}
	}
}
