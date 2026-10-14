#include"snake.h"
void Snake::Print()
{
	for (auto point : snake)
	{
		float x, y;
		x = ToPixel_x(point.Get_x());
		y = ToPixel_y(point.Get_y());
		x = x - X_ChangeSize / 2;
		y = y - Y_ChangeSize / 2;
		float w= X_ChangeSize - 2;
		float h = Y_ChangeSize - 2;
		Retangle retangle((int)x, (int)y, (int)w, (int)h);
		retangle.Print();
	}
}

void Snake::move()
{
	int x, y;
	switch(direction)
	{
	case Snake::UP:
		x = GetHead_x();
		y = GetHead_y() - 1;
		break;
	case Snake::DOWN:
		x = GetHead_x();
		y = GetHead_y() + 1;
		break;
	case Snake::LEFT:
		x = GetHead_x()-1;
		y = GetHead_y();
		break;
	case Snake::RIGHT:
		x = GetHead_x()+1;
		y = GetHead_y();
		break;
	default:
		x = GetHead_x();
		y = GetHead_y();
	}
	if (IsHitWall(x, y))
	{
		dead = true;
		return;
	}
	if (IsHitSelf(x, y))
	{
		dead = true;
		return;
	}
	if (!Isdead()&&!atefood)
	{
		snake.push_front(Point(x, y));
		snake.pop_back();
	}
	else if(!Isdead()&&atefood)
	{
		snake.push_front(Point(x, y));
	}
}

void Snake::SetDirection(Direction dir)
{
	if (this->direction == UP && dir == DOWN ||
		this->direction == DOWN && dir == UP ||
		this->direction == RIGHT && dir == LEFT ||
		this->direction == LEFT && dir ==RIGHT) return ;
	this->direction = dir;
}

bool Snake::Isdead()
{
	return this->dead;
}

bool Snake::IsHitWall(int x,int y)
{
	if (x <= 0 || x > 101 || y <= 0 || y > 33)
	{
		dead = true;
		return true;
	}
	return false;
}

bool Snake::IsHitSelf(int x, int y)
{
	auto start =snake.begin();
	if (snake.empty()) return false;
	auto end = atefood ? snake.end() : snake.end() - 1;
	for (auto i = start;i != end;i++)
	{
		if (i->Get_x() == x && i->Get_y() == y)
		{
			dead = true;
			return true;
		}
	}
	return false;
}

vector<int>Snake::NextHeadPosition()
{
	int x, y;
	switch (direction)
	{
	case Snake::UP:
		x = GetHead_x();
		y = GetHead_y() - 1;
		break;
	case Snake::DOWN:
		x = GetHead_x();
		y = GetHead_y() + 1;
		break;
	case Snake::LEFT:
		x = GetHead_x() - 1;
		y = GetHead_y();
		break;
	case Snake::RIGHT:
		x = GetHead_x() + 1;
		y = GetHead_y();
		break;
	default:
		x = GetHead_x();
		y = GetHead_y();
	}
	vector<int>point({ x,y });
	return point;
}

void Snake::ReInitSnake()
{
	snake.emplace_back(51, 16);
	snake.emplace_back(51, 17);
	snake.emplace_back(51, 18);
	direction = Direction::UP;
	dead = false;
}

void Snake::SnakeClear()
{
	snake.clear();
}