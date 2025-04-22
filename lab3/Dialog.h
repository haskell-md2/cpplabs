#pragma once

#include "Drawnable.h"


class Dialog
{
	private:
		SDL_Window * _win;
		SDL_Renderer* _rend;
		std::string _title, _msg;

	public:
		Dialog(std::string title, std::string msg) : _title(title), _msg(msg), _win(NULL), _rend(NULL) {};
		void Show();
};

