#include "NaviagetButton.h"

void NaviagetButton::ClickAction()
{
	Page * pg = &_pages->at(_param);
	//std::cout << _param;
	pg->show();
	*_current_page = pg;
}
