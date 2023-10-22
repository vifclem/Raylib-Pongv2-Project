#include "raylib.h"
#include <string>
#include <math.h>
#include "Ball.h"
#include "Paddle.h"


Ball ball;
Paddle paddleR;
Paddle paddleL;

#pragma region Points
int PlayerPoints = 0;
int AIpoints = 0;
#pragma endregion


void Update();
void Draw();
const int screenWidth = 800;
const int screenHight = 450;

int main(void)
{
	

	InitWindow(screenWidth, screenHight, " Test game");
	paddleR = Paddle(screenWidth - 80, 200, 21, 128, 5, false);
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		//update
		Update();

		//Draw
		Draw();

	}

	CloseWindow();

	return 0;
}



void Update() {


	paddleL.Update();
	ball.Update();
	
#pragma region CollsionLeft
	RectangleI ballRect = ball.GetRect();
	RectangleI paddleLRect = paddleL.GetRect();
	bool collidingL = Collision::AABBCollision(ballRect, paddleLRect);
	if (collidingL) {
		ball.HorizontalBounce(paddleLRect.x + paddleLRect.width);
	}
#pragma endregion

	
#pragma region CollsionRight
	
	RectangleI paddleRRect = paddleR.GetRect();
	bool collidingR = Collision::AABBCollision(ballRect, paddleRRect);
	if (collidingR) {
		ball.HorizontalBounce(paddleRRect.x - paddleRRect.width);
	}
#pragma endregion

#pragma region PointsCount
	if (ball.GetX() > screenHight) {
		++PlayerPoints;
	}
	if (ball.GetX() < 0) {
		++AIpoints;
	}
#pragma endregion


}

void Draw() {
	BeginDrawing();
	ClearBackground(WHITE);
	DrawFPS(20, 20);

    ball.Draw();
	paddleL.Draw();
	paddleR.Draw();
	

	EndDrawing();
}
