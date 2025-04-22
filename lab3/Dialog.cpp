#include "Dialog.h"


void Dialog::Show()
{
	SDL_CreateWindowAndRenderer(_title.c_str(), 250, 100, 0, &_win, &_rend);


	TTF_TextEngine* eng = TTF_CreateRendererTextEngine(_rend);

	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);



	TTF_Text* text = TTF_CreateText(eng, Sans, _msg.c_str(), _msg.length());


	SDL_SetRenderDrawColor(_rend, 255, 255, 255, 255);

	SDL_FRect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 250;
	rect.h = 100;



	SDL_RenderRect(_rend, &rect);
	SDL_RenderFillRect(_rend, &rect);

	SDL_SetRenderDrawColor(_rend, 0, 0, 0, 255);


	TTF_SetTextColor(text, 100, 100, 100, 255);

	//int x_addition = rect.w / 2 - (_msg.length() / 2) * 20;

	TTF_DrawRendererText(text, 10, 50);
	SDL_RenderPresent(_rend);

	TTF_DestroyRendererTextEngine(eng);
	TTF_DestroyText(text);
	TTF_CloseFont(Sans);
}
