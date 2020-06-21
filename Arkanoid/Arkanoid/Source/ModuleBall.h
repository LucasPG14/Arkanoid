#pragma once

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Collider;

class ModuleBall : public Module
{
public:
	// Constructor
	ModuleBall(bool startEnabled);

	// Destructor
	~ModuleBall();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;
public:

	fPoint ballPosition;

	float speedX = 2.0;
	float speedY = 2.0;

	Animation ballAnim;

	Collider* ballCollider = nullptr;

	bool spacePressed = false;
};
