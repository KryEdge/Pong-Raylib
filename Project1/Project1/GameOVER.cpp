#include "raylib.h"
#include "Players.h"
#include "game.h"

void gameOVER()
{
	BeginDrawing();
	ClearBackground(BLACK);
	if (contadorP1 == 5)
	{
		DrawText("Felicidades Jugador 1!", 100, screenHeight / 4, 50, WHITE);
	}
	if (contadorP2 == 5)
	{
		DrawText("Felicidades Jugador 2!", 100, screenHeight / 4, 50, WHITE);
	}
	DrawText(FormatText(" %i", contadorP1), 260, 300, 30, WHITE);
	DrawText(FormatText("Puntaje J1:"), 100, 300, 30, WHITE);

	DrawText(FormatText(" %i", contadorP2), 570, 300, 30, WHITE);
	DrawText(FormatText("Puntaje J2:"), 400, 300, 30, WHITE);

	DrawText("Para jugar otra vez presione Enter", 100, 350, 35, WHITE);
	if (IsKeyPressed(KEY_ENTER))
	{
		game = true;
		contadorP1 = 0;
		contadorP2 = 0;
	}
	DrawText("Para volver al menu presione Q", 100, 390, 35, WHITE);
	if (IsKeyPressed(KEY_Q))
	{
		contadorP1 = 0;
		contadorP2 = 0;
		LoadTexture("Assets/Title.png");
	}

	EndDrawing();
}