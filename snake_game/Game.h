#pragma once
#include"tools.h"
#include"Food.h"
#include"Shape.h"
#include"Snake.h"
#include"Menu.h"

class Game {
public:
	enum State//状态枚举
	{
		MENU, PLAYING, OVER
	};
	void SetState(State state);//建立新状态
	void Run();
	Game();
private:
	void HandleInput();//获取按键信息
	void Update();//更新
	void RenderObject();//渲染游戏角色
	void RenderTitle(const string& Title, int y);//渲染文字;
	Snake snake;
	Food food;
	bool Running = true;
	Uint64 LastMoveTime = 0;//上次移动的时间
	Menu menu;
	State state=MENU;
};