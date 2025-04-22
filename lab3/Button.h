#pragma once

#include "Drawnable.h"
#include <iostream>
#include <vector>



class Button : public Drawnable
{
	private:
		std::string _value;
		GVector _position, _size;
		//std::vector<Page>* _pages;
		//std::vector<Dialog>* _dialogs;

	public:
		Button(std::string val, GVector pos, GVector size) : _value(val), _position(pos), _size(size) {}
		/* Button(std::string val, GVector pos, GVector size, std::vector<Dialog>* dialogs, int param) : _value(val), _position(pos), _size(size), _dialogs(dialogs), _param(param) {}*/

		void Draw(SDL_Renderer* renderer) override;
		Drawnable_Type GetType() override;
		bool inArea(float x, float y);
		virtual void ClickAction() = 0;

};

