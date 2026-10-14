#pragma once
#include"Shape.h"
#include<random>
#include<iostream>
class  Food
{
public:
	Food() :engine(rd())
	{
		Respawn();//重新渲染food
	}
	Food(const Food&) = delete;//禁止拷贝构造
	Food& operator=(const Food&) = delete;//禁止拷贝赋值
	void Print()
	{
		shape->Print();
	}
	int Get_x() const { return shape->Get_x(); }
	int Get_y() const { return shape->Get_y(); }
	void Respawn();
private:
	unique_ptr<Shape> shape;
	random_device rd;//随机树种子
	mt19937 engine;//随机数引擎
	uniform_int_distribution<int>RandPosition_X{1,101};//x坐标分布
	uniform_int_distribution<int>RandPosition_Y{ 1,33 };//y坐标分布
	uniform_real_distribution<float>RandColor{0.0f,1.0f};//颜色分布
};