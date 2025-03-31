#pragma once

#include <vector>
#include <string>
#include <type_traits>

#include "Button.h"
#include "Drawnable.h"

#include <iostream>

class Page
{
	private:
		std::vector<Drawnable*> _objects;
		std::string _name;
		SDL_Renderer* _renderer;

	public:
		Page(std::string name, SDL_Renderer* renderer) : _name(name), _renderer(renderer) {}
		void show();
		void addObject(Drawnable* obj);
		void holdEvents(SDL_Event* e);
};

