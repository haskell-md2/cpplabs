#pragma once

#include <SDL.h>

class Drawnable
{
public:
	virtual void Draw(SDL_Renderer* renderer) = 0;

};

