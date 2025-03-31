#pragma once

#include <string>
#include <SDL3/SDL.h>

class Dialog
{
	private:
		SDL_Window * _win;
		std::string _title, _msg;

	public:
		Dialog(std::string title, std::string msg, SDL_Window * win) : _title(title), _msg(msg), _win(win){}
		void Show();
};

