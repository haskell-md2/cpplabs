#include "Kernel.h"



void Kernel::Draw(SDL_Renderer* renderer){

	tracer->Update();
	tracer->Draw(renderer);

	SDL_Rect rect;
	rect.x = pos.x();
	rect.y = pos.y();
	rect.w = size.x();
	rect.h = size.y();

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void Kernel::Right()
{
	tracer->AddTrace(pos.x(), pos.y() + size.y() / 2, size.y(), Mode::Horizontal);

	GVector velocity{ 1, 0 };
	pos = pos + velocity * vel;
	
}

void Kernel::Left()
{
	tracer->AddTrace(pos.x() + size.x() - 3, pos.y() + size.y() / 2, size.y(), Mode::Horizontal);
	
	GVector velocity{ -1 , 0 };
	pos = pos + velocity * vel;
}

void Kernel::Down()
{
	tracer->AddTrace(pos.x() + size.x() /2, pos.y(), size.x(), Mode::Vertical);
	
	GVector velocity{0, 1 };
	pos = pos + velocity * vel;
}

void Kernel::Up()
{
	tracer->AddTrace(pos.x() + size.x() / 2, pos.y() + size.y(), size.x(), Mode::Vertical);
	
	GVector velocity{ 0, -1 };
	pos = pos + velocity * vel;
}

