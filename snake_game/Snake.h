

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
	enum Direction//定义方向
	{
		UP, DOWN, LEFT, RIGHT
	};
	Snake()//snake构造函数，构造初始蛇身，初始方向 
	{
		snake.emplace_back(51, 16);
		snake.emplace_back(51, 17);
		snake.emplace_back(51, 18);
		direction = Direction::UP;
	}
	void ReInitSnake();//重新初始化蛇
	void SetAtefood(bool ate) { atefood = ate; }//判断是否迟到食物
	void SetDirection(Direction dir);//改变方向
	void Print();//渲染
	int GetHead_x() const { return snake.front().Get_x(); }//获取格子坐标
	int GetHead_y() const { return snake.front().Get_y(); }
	void move();//移动
	bool Isdead();//是否死亡
	void SnakeClear();//清除当前蛇身
	vector<int> NextHeadPosition();//获取头部x,y坐标
private:
	deque<Point>snake;//双端队列构造蛇身
	bool dead = false;
	Direction direction;
	bool IsHitWall(int x, int y);//判断是否撞墙
	bool IsHitSelf(int x, int y);//判断是否撞到自己
	bool atefood = 0;
};