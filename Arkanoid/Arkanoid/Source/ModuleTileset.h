#pragma once

#include "Module.h"
#include "SDL/include/SDL_rect.h"
#include "p2Point.h"

struct SDL_Texture;

class ModuleTileset : public Module
{
public:
	enum class TileType
	{
		NONE = -1,
		EMPTY,
		WALL,
		HITBLOCK1,
		HITBLOCK2
	};

	struct Tile
	{
		TileType id;
		SDL_Rect tileRect;
	};

	ModuleTileset(bool startEnabled);
	~ModuleTileset();

	bool Init() override;

	bool Start() override;

	void changeTile(iPoint tile, bool touchingHigh);

	//update_status PostUpdate() override;

	bool CleanUp() override;

	//getter
	Tile getTileLevel(int y, int x);

	Tile levelToTile[32][28] = {};

	int(*level)[28] = nullptr;
};