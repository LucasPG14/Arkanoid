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


	for (int i = 0; i < 32; ++i)
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

void ModuleTileset::changeTile(iPoint tile, bool touchingHigh)
{
	if (tile.x % 2 == 0)
	{
		if (touchingHigh)
		{
			if (getTileLevel(tile.y + 1.5f, tile.x).id == TileType::HITBLOCK2)
			{
				levelToTile[tile.y + 1][tile.x].id = TileType::HITBLOCK1;
				levelToTile[tile.y + 1][tile.x - 1].id = TileType::HITBLOCK1;
			}

			else if (getTileLevel(tile.y, tile.x).id == TileType::HITBLOCK1)
			{
				levelToTile[tile.y + 1][tile.x].id = TileType::EMPTY;
				levelToTile[tile.y + 1][tile.x - 1].id = TileType::EMPTY;
			}
		}
		else 
		{
			if (getTileLevel(tile.y, tile.x).id == TileType::HITBLOCK2)
			{
				levelToTile[tile.y][tile.x].id = TileType::HITBLOCK1;
				levelToTile[tile.y][tile.x - 1].id = TileType::HITBLOCK1;
			}

			else if (getTileLevel(tile.y, tile.x).id == TileType::HITBLOCK1)
			{
				levelToTile[tile.y][tile.x].id = TileType::EMPTY;
				levelToTile[tile.y][tile.x - 1].id = TileType::EMPTY;
			}
		}
	}

	else if (tile.x % 2 != 0)
	{
		if (touchingHigh)
		{
			if (getTileLevel(tile.y + 1.5f, tile.x).id == TileType::HITBLOCK2 && getTileLevel(tile.y + 1.5f, tile.x - 1).id != TileType::WALL)
			{
				levelToTile[tile.y + 1][tile.x].id = TileType::HITBLOCK1;
				levelToTile[tile.y + 1][tile.x + 1].id = TileType::HITBLOCK1;
			}

			else if (getTileLevel(tile.y + 1.5f, tile.x).id == TileType::HITBLOCK1 && getTileLevel(tile.y + 1.5f, tile.x - 1).id != TileType::WALL)
			{
				levelToTile[tile.y + 1][tile.x].id = TileType::EMPTY;
				levelToTile[tile.y + 1][tile.x + 1].id = TileType::EMPTY;
			}
		}
		else
		{
			if (getTileLevel(tile.y, tile.x).id == TileType::HITBLOCK2 && getTileLevel(tile.y, tile.x - 1).id != TileType::WALL)
			{
				levelToTile[tile.y][tile.x].id = TileType::HITBLOCK1;
				levelToTile[tile.y][tile.x + 1].id = TileType::HITBLOCK1;
			}

			else if (getTileLevel(tile.y, tile.x).id == TileType::HITBLOCK1 && getTileLevel(tile.y, tile.x - 1).id != TileType::WALL)
			{
				levelToTile[tile.y][tile.x].id = TileType::EMPTY;
				levelToTile[tile.y][tile.x + 1].id = TileType::EMPTY;
			}
		}
	}
}

bool ModuleTileset::CleanUp()
{


	return true;
}

ModuleTileset::Tile ModuleTileset::getTileLevel(int y, int x)
{
	return levelToTile[y][x];				
}