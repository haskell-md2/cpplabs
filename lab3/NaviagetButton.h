#pragma once

#include "Button.h"
#include "Page.h"

class NaviagetButton : public Button
{
	private: 

		std::vector<Page>* _pages;
		int _param;
		Page ** _current_page;

	public:
		NaviagetButton(std::string val, GVector pos, GVector size, Page ** current_page, std::vector<Page> * pages, int param) : Button(val, pos, size), _current_page(current_page), _pages(pages), _param(param) {}
		void ClickAction() override;
};

