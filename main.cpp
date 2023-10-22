#include "raylib.h"
#include <string>
#include <math.h>
#include "Ball.h"
#include "Paddle.h"


Ball ball;
Paddle paddle;

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


	
	paddle.Update();
	ball.Update();




}

void Draw() {
    ball.Draw();
	paddle.Draw();
	BeginDrawing();
	ClearBackground(WHITE);
	DrawFPS(20, 20);

	EndDrawing();
}