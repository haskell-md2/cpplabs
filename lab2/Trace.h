#pragma once

#include "Drawnable.h"
#include "GVector.h"
#include <deque>

using namespace std;

enum class Mode{Horizontal, Vertical};

struct trace_point {

	GVector pos;
	int size;
	Mode m;
};

class Trace : public Drawnable
{
	private:
		deque<trace_point> traces;

	public:
		Trace();
		void Update();
		void AddTrace(int x, int y, int size, Mode m);

		void Draw(SDL_Renderer* renderer) override;
};

