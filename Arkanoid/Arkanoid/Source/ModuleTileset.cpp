#include "ModuleTileset.h"

#include "Globals.h"
#include "Application.h"

#include "ModuleCollisions.h"
#include "ModuleRender.h"
#include "Scene1.h"

#include "Tileset.h"

ModuleTileset::ModuleTileset(bool startEnabled) : Module(startEnabled)
{

}

ModuleTileset::~ModuleTileset()
{

}

bool ModuleTileset::Init()
{
	return true;
}

bool ModuleTileset::Start()
{
	if (App->scene1->IsEnabled() == true)
	{
		level = level1;
	}
	else { return false; }


	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 28; ++j)
		{
			switch (level[i][j])
			{
			case 0:
				levelToTile[i][j] =
				{
					TileType::EMPTY,
					{i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE,TILE_SIZE}
				};
				break;

			case 1:
				levelToTile[i][j] =
				{
					TileType::WALL,
					{i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE,TILE_SIZE}
				};
				break;

			case 2:
				levelToTile[i][j] =
				{
					TileType::HITBLOCK1,
					{i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE,TILE_SIZE}
				};
				break;

			case 3:
				levelToTile[i][j] =
				{
					TileType::HITBLOCK2,
					{i * TILE_SIZE, j * TILE_SIZE, TILE_SIZE,TILE_SIZE}
				};
				break;
			}
		}
	}

	return true;
}

void ModuleTileset::changeTile(iPoint tile)
{
	
}

bool ModuleTileset::CleanUp()
{


	return true;
}

ModuleTileset::Tile ModuleTileset::getTileLevel(int y, int x)
{
	return levelToTile[y][x];				
}