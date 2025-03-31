#include "Button.h"

void Button::Draw(SDL_Renderer* renderer)
{

	TTF_TextEngine* eng = TTF_CreateRendererTextEngine(renderer);

	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

	const char* v = _value.c_str();


	int text_len = _value.length();

	TTF_Text* text = TTF_CreateText(eng, Sans, v, text_len);


	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_FRect rect;
	rect.x = _position.x();
	rect.y = _position.y();
	rect.w = _size.x();
	rect.h = _size.y();
	


	SDL_RenderRect(renderer, &rect);
	//DL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);


	TTF_SetTextColor(text, 100, 100, 100, 255);

	int x_addition = rect.w / 2 - (text_len/2) *  20;

	TTF_DrawRendererText(text, _position.x() + x_addition, _position.y());

	TTF_DestroyRendererTextEngine(eng);
	TTF_DestroyText(text);
	TTF_CloseFont(Sans);

	
}

Drawnable_Type Button::GetType()
{
	return BUTTON;
}


bool Button::inArea(float x, float y)
{
	bool cor_x = (_position.x() < x) && (x < _position.x() + _size.x());
	bool cor_y = (_position.y() < y) && (y < _position.y() + _size.y());
	return cor_x && cor_y;

}

void Button::ClickAction()
{
	if (_fun) {
		_fun(_params);
	}

}
