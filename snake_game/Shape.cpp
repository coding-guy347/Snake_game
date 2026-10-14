#include"Shape.h"
void Point::Print(){}

void Retangle::Print()
{
	SDL_SetRenderDrawColorFloat(renderer,this->color[0], this->color[1],this->color[2],1.0f);
	SDL_FRect rect= { (float)x,(float)y,(float)width,(float)height };
	SDL_RenderFillRect(renderer, &rect);
}

void Triangle::Print()
{
	float apex_x = (float)(this->x* X_ChangeSize);
	float apex_y = (float)(this->y * Y_ChangeSize-Y_ChangeSize);
	float left_x = (float)(this->x * X_ChangeSize-X_ChangeSize);
	float left_y = (float)(this->y  * Y_ChangeSize+Y_ChangeSize);
	float right_x = (float)(this->x  * X_ChangeSize+X_ChangeSize);
	float right_y = (float)(this->y  * Y_ChangeSize+Y_ChangeSize);
	SDL_Vertex vertices[3] = {
		 {.position = { left_x, left_y }, .color = { this->color[0], this->color[1], this->color[2],1}},
		 
		{.position = { apex_x, apex_y }, .color = { this->color[0], this->color[1], this->color[2],1} },
		
		{.position = { right_x, right_y }, .color = { this->color[0], this->color[1], this->color[2],1}}
	};
	SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);
}

void Cycle::Print()
{
	float r = X_ChangeSize;
	float CenterPoint_x = (float)(this->Get_x() * X_ChangeSize);
	float CenterPoint_y = (float)(this->Get_y() * Y_ChangeSize);
	vector<Point>points;
	for (int i =0;i <= 360;i++)
	{
		Point point((int)(CenterPoint_x +r* cos(i*PI/180)),(int)(CenterPoint_y-r*sin(i*PI/180)));
		points.push_back(point);
	}
	for (int i = 0;i <360;i++)
	{
		float apex_x = CenterPoint_x;
		float apex_y = CenterPoint_y;
		float left_x = (float)points[i].Get_x();
		float left_y = (float)points[i].Get_y();
		float right_x = (float)points[i + 1].Get_x();
		float right_y = (float)points[i + 1].Get_y();
		SDL_Vertex vertices[3] = {
			 {.position = { left_x, left_y }, .color = { this->color[0], this->color[1], this->color[2],1}},

			{.position = { apex_x, apex_y }, .color = { this->color[0], this->color[1], this->color[2],1} },

			{.position = { right_x, right_y }, .color = { this->color[0], this->color[1], this->color[2],1}}
		};
		SDL_RenderGeometry(renderer, NULL, vertices, 3, NULL, 0);
	}
}

void FivePointStar::Print()
{
}

