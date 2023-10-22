#include "Ball.h"
#include <raylib.h>
#include <cstdlib> 




Ball::Ball(int positionX, int positionY, int speedx, int speedy, int radus, Color color) {

	positionX = GetRandomValue(0, GetScreenWidth());
	positionY = GetRandomValue(0, GetScreenHeight());
	speedx = GetRandomValue(2, 10);
	speedy = GetRandomValue(2, 10);
	radus = 30;
	color = RED;

}

Ball::Ball() {

	positionX = GetRandomValue(0, GetScreenWidth());
	positionY = GetRandomValue(0, GetScreenHeight());
	speedx = GetRandomValue(2, 10);
	speedy = GetRandomValue(2, 10);
	radus = GetRandomValue(5, 20);
	color = BLUE;

}

Ball::~Ball() {

}

void Ball::Update() {

	positionX += speedx;
	positionY += speedy;


	if (positionY > GetScreenHeight() - radus) {

		VerticalBounce(GetScreenHeight() - radus);
		bounceNumer += 1;

	}
	if (positionY < 0) VerticalBounce(0);



	if (positionX > GetScreenWidth() - radus) {

		HorizontalBounce(GetScreenWidth() - radus);
		bounceNumer += 1;
	}
	if (positionX < 0) HorizontalBounce(0);

}

void Ball::Draw() {

	DrawCircle(positionX, positionY, radus, color);
	if (bounceNumer > 3) DrawCircle(positionX, positionY, radus, BLUE);
}


void Ball::HorizontalBounce(int newX) {
	speedx = -speedx;
	positionX = newX;
}
void Ball::VerticalBounce(int newY) {
	speedy = -speedy;
	positionY = newY;
}

RectangleI Ball::GetRect() {
	return RectangleI{ positionX, positionY, radus, radus};
}
