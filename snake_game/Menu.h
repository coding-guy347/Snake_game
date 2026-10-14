#pragma once
#include<string>
#include<array>
#include<memory>
#include "tools.h"
#include<iostream>
using namespace std;
class  Menu
{
public:
	string Title;
	string StartReminderTitle;
	string EndReminderTitle_1;
	string EndReminderTitle_2;
	Menu()//menu构造函数
	{
		Title = "Gready Snake";
		StartReminderTitle = "Click SPACE to start";
		EndReminderTitle_1 = "Click R to restart";
		EndReminderTitle_2 = "Click ECS to end";
		font=TTF_OpenFont(FindAsset("msyh.ttc").c_str(), 48);
		if (!font) cout << "font load failed: " << SDL_GetError() << endl;//异常抛出
		color = { 255,192,203,255 };
	 }
	~Menu()
	{
		TTF_CloseFont(font);
	}
	void PrintTitle(const string&title,int y);
private:
	array<int, 4>color;
	TTF_Font* font = nullptr;
};
