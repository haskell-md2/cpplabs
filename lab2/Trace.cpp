#include "Trace.h"
#include <iostream>

Trace::Trace()
{
	//NOTHING
}

void Trace::Update()
{
	
	for (auto &tr : traces) {
		if ((tr.size > 300 && tr.m == Mode::Horizontal) || (tr.size > 500 && tr.m == Mode::Vertical)) {
			traces.pop_front();
		}
		else
		{
			tr.size ++;
		}
		
	}


}

void Trace::AddTrace(int x, int y, int size, Mode m)
{
	traces.push_back({ GVector(x,y),size, m});
	
}


void Trace::Draw(SDL_Renderer* renderer)
{

	SDL_Rect rect;

	
	for (auto tr : traces) {


		if (tr.m == Mode::Horizontal) {
			rect.w = 10;

			rect.h = tr.size;

			rect.x = tr.pos.x();
			rect.y = tr.pos.y() - tr.size / 2;

			SDL_SetRenderDrawColor(renderer, 255 / tr.size * 10, 255 / tr.size * 10, 255 / tr.size * 10, 255 / tr.size * 10);

			SDL_RenderDrawRect(renderer, &rect);
			SDL_RenderFillRect(renderer, &rect);
		}
		else if(tr.m == Mode::Vertical)
		{
			rect.h = 10;
			rect.w = tr.size;

			rect.x = tr.pos.x() - tr.size / 2;
			rect.y = tr.pos.y();

			SDL_SetRenderDrawColor(renderer, 255 * 50 / tr.size, 255 * 50 / tr.size , 255 * 50 / tr.size , 255 * 50 / tr.size);

			SDL_RenderDrawRect(renderer, &rect);
			SDL_RenderFillRect(renderer, &rect);
		}

	
	}



	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

}


