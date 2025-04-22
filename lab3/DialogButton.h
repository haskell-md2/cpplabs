#pragma once

#include "Button.h"
#include "Dialog.h"

class DialogButton : public Button
{
	private:
		int _param;
		std::vector<Dialog>* _dialogs;

	public:
		DialogButton(std::string val, GVector pos, GVector size, std::vector<Dialog>* dialogs, int param) : Button(val, pos, size),_dialogs(dialogs), _param(param) {}
		void ClickAction() override;
};

