#include "raylib.h"
#include "game.h"
#include "GMenu.h"
#include "GOver.h"

int main(void)
{
	InitWindow(screenWidth, screenHeight, "Bad Pong");
	InitAudioDevice();
	SetTargetFPS(60);   

	while (!WindowShouldClose())
	{
		if (!game && (contadorP1 < 5 && contadorP2 < 5))
		{
			loadMenu();
		}

		if (game)
		{
			playGame();
		}
		
		if (!game && (contadorP1 == 5 || contadorP2 == 5))
		{
			endGame();
		}
	}

	CloseAudioDevice();
	CloseWindow();
	return 0;
}
