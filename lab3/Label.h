#pragma once

#include "Drawnable.h"

class Label : public Drawnable
{
	private:
		std::string _value;
		GVector _position;

	public:
		Label(std::string val, GVector pos) : _value(val), _position(pos) {}
		void Draw(SDL_Renderer* renderer) override;
		Drawnable_Type GetType() override;
};

