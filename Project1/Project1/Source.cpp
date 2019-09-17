#include "raylib.h"
#include "game.h"

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Bad Pong");
	InitAudioDevice();
	SetTargetFPS(60);   

	while (!WindowShouldClose())
	{
		if (game)
		{
			playGame();
		}
		else if (!game && (contadorP1 < 5 && contadorP2 < 5))
		{
			gameMenu();
		}
		if (!game && (contadorP1 == 5 || contadorP2 == 5))
		{
			gameOver();
		}
	}
	CloseAudioDevice();
	CloseWindow();
	return 0;
}
