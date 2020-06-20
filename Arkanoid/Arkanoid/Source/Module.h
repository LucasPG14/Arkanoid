#pragma once

#include "Globals.h"

struct Collider;

class Module
{
public:
	Module(bool startEnabled);

	virtual bool Init();


	virtual bool Start();

	virtual update_status PreUpdate();

	virtual update_status Update();

	virtual update_status PostUpdate();

	virtual bool CleanUp();


	void Enable();

	void Disable();

	inline bool IsEnabled() const { return isEnabled; }

private:
	bool isEnabled = true;
};