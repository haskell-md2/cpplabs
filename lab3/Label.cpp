#include "Label.h"

#include <iostream>

void Label::Draw(SDL_Renderer* renderer)
{

	TTF_TextEngine * eng = TTF_CreateRendererTextEngine(renderer);

	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

	const char* v = _value.c_str();
	TTF_Text* text = TTF_CreateText(eng,Sans,v, _value.length());
	

	
	TTF_SetTextColor(text, 100, 100, 100, 255);
	
	TTF_DrawRendererText(text, _position.x(), _position.y());


	TTF_DestroyRendererTextEngine(eng);
	TTF_DestroyText(text);
	TTF_CloseFont(Sans);
}

Drawnable_Type Label::GetType()
{
	return LABEL;
}

