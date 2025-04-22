#include "DialogButton.h"

void DialogButton::ClickAction()
{
	_dialogs->at(_param).Show();
}
