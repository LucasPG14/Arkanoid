#pragma once

#include "Module.h"

#define DEFAULT_MUSIC_FADE_TIME 2.0f
#define MAX_FX 200

struct _Mix_Music;
struct Mix_Chunk;
typedef struct _Mix_Music Mix_Music;

class ModuleAudio : public Module
{
public:
	ModuleAudio(bool startEnabled);

	~ModuleAudio();


	bool Init();


	bool CleanUp();

	bool PlayMusic(const char* path, float fade_time = DEFAULT_MUSIC_FADE_TIME);

	uint LoadFx(const char* path);


	bool PlayFx(uint index, int repeat = 0);

private:

	Mix_Music* music = nullptr;

	Mix_Chunk* soundFx[MAX_FX] = { nullptr };
};