#pragma once
#include"tools.h"
#include"Food.h"
#include"Shape.h"
#include"Snake.h"
#include"Menu.h"

class Game {
public:
	enum State
	{
		MENU, PLAYING, OVER
	};
	void SetState(State state);
	void Run();
	Game();
private:
	void HandleInput();
	void Update();
	void RenderObject();
	void RenderTitle(const string& Title, int y);
	Snake snake;
	Food food;
	bool Running = true;
	Uint64 LastMoveTime = 0;
	Menu menu;
	State state=MENU;
};