#include"Menu.h"

void Menu::PrintTitle(const string&Title,int y)
{
	RenderText(font, Title, renderer,y,color);
}
