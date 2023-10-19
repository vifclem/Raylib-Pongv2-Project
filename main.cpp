#include "raylib.h"
#include <string>
#include <math.h>
#include "Ball.h"


Ball ball;
Vector2 ballPos = { 200, 200 };
int speed = 5;

void Update();
void Draw();

int main(void)
{
	const int screenWidth = 800;
	const int screenHight = 450;

	InitWindow(screenWidth, screenHight, " Test game");

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


	if (IsKeyDown(KEY_W)) ballPos.y -= speed;
	if (IsKeyDown(KEY_S)) ballPos.y += speed;
	if (IsKeyDown(KEY_D)) ballPos.x += speed;
	if (IsKeyDown(KEY_A)) ballPos.x -= speed;

	ball.Update();



}

void Draw() {
    ball.Draw();

	BeginDrawing();
	ClearBackground(WHITE);
	DrawFPS(20, 20);
	DrawRectangle(ballPos.x, ballPos.y, 20, 20, RED);

	EndDrawing();
}