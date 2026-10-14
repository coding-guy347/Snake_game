
/*
* 第一次用的像素坐标，画出的实心矩形不好保证后续的的
* snake具有缝隙，换成格子坐标，横向102格，纵向34
*/
#pragma once
#include"Shape.h"
#include<deque>
#include"tools.h"
#include<array>
#include"Food.h"
#include<cmath>
using namespace std;
class Snake
{
public:
	enum Direction
	{
		UP, DOWN, LEFT, RIGHT
	};
	Snake() {
		snake.emplace_back(51, 16);
		snake.emplace_back(51, 17);
		snake.emplace_back(51, 18);
		direction = Direction::UP;
	}
	void ReInitSnake();
	void SetAtefood(bool ate) { atefood = ate; }
	void SetDirection(Direction dir);
	void Print();
	int GetHead_x() const { return snake.front().Get_x(); }
	int GetHead_y() const { return snake.front().Get_y(); }
	void move();
	bool Isdead();
	void SnakeClear();
	vector<int> NextHeadPosition();
private:
	deque<Point>snake;
	bool dead = false;
	Direction direction;
	bool IsHitWall(int x, int y);
	bool IsHitSelf(int x, int y);
	bool atefood = 0;
};