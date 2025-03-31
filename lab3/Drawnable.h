#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_ttf.h>

#include <string>

#include "GVector.h"
#include "Drawnable.h"

typedef enum Drawnable_Type {
	LABEL,
	BUTTON
};


class Drawnable
{
public:
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual Drawnable_Type GetType() = 0;
};

