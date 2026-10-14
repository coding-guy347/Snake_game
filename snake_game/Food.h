#pragma once
#include"Shape.h"
#include<random>
#include<iostream>
class  Food
{
public:
	Food() :engine(rd())
	{
		Respawn();
	}
	Food(const Food&) = delete;
	Food& operator=(const Food&) = delete;
	void Print()
	{
		shape->Print();
	}
	int Get_x() const { return shape->Get_x(); }
	int Get_y() const { return shape->Get_y(); }
	void Respawn();
private:
	unique_ptr<Shape> shape;
	friend class Snake;
	random_device rd;
	mt19937 engine;
	uniform_int_distribution<int>RandPosition_X{1,101};
	uniform_int_distribution<int>RandPosition_Y{ 1,33 };
	uniform_real_distribution<float>RandColor{0.0f,1.0f};
};