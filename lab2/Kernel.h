#pragma once
#include "Drawnable.h"
#include "Trace.h"
#include "GVector.h"

class Kernel : public Drawnable{
private:
	
	GVector size, pos;
	int vel;
	SDL_Renderer * renderer;
	Trace * tracer;

public:
	Kernel(int w, int h, int x, int y, int svel, SDL_Renderer* rend, Trace* tr) : size(w, h), pos(x, y), vel(svel), renderer(rend), tracer(tr) {}

	void Draw(SDL_Renderer* renderer) override;

	void Right();
	void Left();
	void Down();
	void Up();
};
