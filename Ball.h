#pragma once
#include <raylib.h>
#include <math.h>
#include "Collision.h"



class Ball
{
private:
	int positionX;
	int positionY;
	int speedx;
	int speedy;
	int radus;
	Color color;



public:

	int bounceNumer;
	Ball(int positionX, int positionY, int speedx, int speedy, int radus, Color color);
	Ball();
	~Ball();

	RectangleI GetRect();
	void HorizontalBounce(int newX);
	void VerticalBounce(int newY);
	void Update();
	void Draw();
	int GetX();

};

