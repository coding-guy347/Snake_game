#pragma once
#include"tools.h"
#include<vector>
#include<array>
#include<cmath>
#include<memory>
#define PI 3.1415926
using namespace std;
class Shape//父类shape
{
protected:
	array<float, 3>color;//浮点颜色数组(都是0~1的浮点值)
	inline static vector<unique_ptr<Shape>>prototypes;//定义静态原型模式
	int x, y;
public:
	void SetPosition(int newX, int newY)//建立新格子坐标 
	{
		x = newX;
		y = newY;
	}
	void SetColor(const array<float, 3>& newColor)//建立新颜色
	{
		color = newColor;
	}
	static int  GetPrototypeCount()  { return prototypes.size(); }//获取当前原型数量
	Shape(int x=0,int y=0,const array<float,3>color={0.3f,0.4f,0.3f}) :x(x), y(y), color(color) {}//初始化shape类
	virtual void Print() {};
	virtual ~Shape()=default;
	virtual unique_ptr<Shape> clone() { return nullptr; }
	int Get_x() const { return x; }
	int Get_y() const { return y; }
	static void addPrototype(unique_ptr<Shape> shape)
	{
		prototypes.push_back(move(shape));
	}
	static unique_ptr<Shape>FindAndClone(int index) //找到需要建立的shape类并且克隆
	{
		if (index < 0 || index >= (int)prototypes.size()) return nullptr;
		return prototypes[index]->clone();
	}
};

class Point:public Shape {
private:
public:
	Point(int x, int y) :Shape(x, y) {};
	void Print();
	unique_ptr<Shape>clone() override {//重载当前子类的clone函数
		return make_unique<Point>(*this);
	}
};

class Retangle :public Shape {
private:
	int width, height;
public:
	Retangle(int x, int y, int w, int h, const array<float, 3>color={0.3f,0.3f,0.6f}) :Shape(x, y,color), width(w), height(h) {}
	void Print();
	unique_ptr<Shape> clone() override {
		return make_unique<Retangle>(*this);
	}
};

class Triangle :public Shape {
private:
public:
	 Triangle(int x,int y,const array<float,3>color={0.3f,0.4f,0.3f}) :Shape(x, y,color) {}
	unique_ptr<Shape> clone()override {
		return make_unique<Triangle>(*this);
	}
	void Print();
};

class Cycle:public Shape
{
private:
public:
	Cycle(int x, int y, const array<float, 3>color = { 0.3f,0.4f,0.3f }) : Shape(x, y, color) {}
	unique_ptr<Shape>clone()override {
		return make_unique<Cycle>(*this);
	}
	void Print();
};

class FivePointStar :public Shape
{
private:
public:
	FivePointStar(int x, int y, const array<float, 3>color = { 0.3f,0.4f,0.3f }) : Shape(x, y, color) {}
	unique_ptr<Shape> clone()override {
		return make_unique<FivePointStar>(*this);
	}
	void Print();
};