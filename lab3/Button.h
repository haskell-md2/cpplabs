#pragma once

#include "Drawnable.h"

#include <iostream>


class Button : public Drawnable
{
	private:
		std::string _value;
		GVector _position, _size;
		void(*_fun)(void*);
		void* _params;



	public:
		Button(std::string val, GVector pos, GVector size, void(*fun)(void*),  void* params) : _value(val), _position(pos), _size(size), _fun(fun), _params(params) {}
		void Draw(SDL_Renderer* renderer) override;
		Drawnable_Type GetType() override;
		typedef void(*func)();
		bool inArea(float x, float y);
		void ClickAction();
};

