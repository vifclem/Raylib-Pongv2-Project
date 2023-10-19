#pragma once
#include <raylib.h>
#include <math.h>



class Ball
{
private:
	int positionX;
	int positionY;
	int speedx;
	int speedy;
	float radus;
	Color color;



public:

	int bounceNumer;
	Ball(int positionX, int positionY, int speedx, int speedy, float radus, Color color);
	Ball();
	~Ball();

	void HorizontalBounce(int newX);
	void VerticalBounce(int newY);
	void Update();
	void Draw();


};

