#include"Food.h"

void Food::Respawn()
{
	int count = Shape::GetPrototypeCount();
	if (count == 0) return;//如果没有注册任何原型就结束
	int posX = RandPosition_X(engine);
	int posY = RandPosition_Y(engine);
	uniform_int_distribution<int>shapeIndex(0, count - 1);
	shape = Shape::FindAndClone(shapeIndex(engine));
	if (shape)
	{
		shape->SetPosition(posX, posY);
		array<float, 3>color = { RandColor(engine),RandColor(engine),RandColor(engine) };
		shape->SetColor(color);
	}
}