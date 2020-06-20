#pragma once 

#include "Module.h"

#define MAX_TEXTURES 50

struct SDL_Texture;

class ModuleTextures : public Module
{
public:

	ModuleTextures(bool startEnabled);

	~ModuleTextures();


	bool Init() override;

	bool CleanUp() override;


	SDL_Texture* const Load(const char* path);

	bool Unload(SDL_Texture* texture);


	void GetTextureSize(const SDL_Texture* texture, uint& width, uint& height) const;

public:

	SDL_Texture* textures[MAX_TEXTURES] = { nullptr };
};