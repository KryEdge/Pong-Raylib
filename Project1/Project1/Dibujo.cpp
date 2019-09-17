#include "game.h"
#include "raylib.h"
#include "pelota.h"
#include "Players.h"

void drawGame()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTexture(backG, 0, 0, WHITE);

	if (numberPUP < 1)
	{
		if (numRand == 200)
		{
			if (pUpRand == 0)
			{
				pUpY = GetRandomValue(40, screenHeight - 40);
				pUpRand = GetRandomValue(1, 3);
			}
			switch (pUpRand)
			{
			case 1:
				pUpPosition1.x = screenWidth / 2;
				pUpPosition1.y = pUpY;
				DrawCircleV(pUpPosition1, radiopUp, PINK);
				break;
			case 2:
				pUpPosition2.x = screenWidth / 2;
				pUpPosition2.y = pUpY;
				DrawCircleV(pUpPosition2, radiopUp, GOLD);
				break;
			case 3:
				pUpPosition3.x = screenWidth / 2;
				pUpPosition3.y = pUpY;
				DrawCircleV(pUpPosition3, radiopUp, VIOLET);
				break;
			default:
				break;
			}
		}
		else
		{
			numRand = GetRandomValue(0, 200);
		}
	}
	switch (color1)
	{
	case 0:
		DrawRectangleRec(Player1, RED);
		break;
	case 1:
		DrawRectangleRec(Player1, SKYBLUE);
		break;
	case 2:
		DrawRectangleRec(Player1, GREEN);
		break;
	case 3:
		DrawRectangleRec(Player1, YELLOW);
		break;
	default:
		break;
	}
	if (!PLAYlong && !PLAYshort)
	{
		DrawTexture(player, Player1.x - 35, Player1.y, WHITE);
	}
	else if (PLAYlong)
	{
		DrawTexture(playerLONG, Player1.x - 35, Player1.y, WHITE);
	}
	else if (PLAYshort)
	{
		DrawTexture(playerSHORT, Player1.x - 35, Player1.y, WHITE);
	}
	switch (color2)
	{
	case 0:
		DrawRectangleRec(Player2, LIGHTGRAY);
		break;
	case 1:
		DrawRectangleRec(Player2, ORANGE);
		break;
	case 2:
		DrawRectangleRec(Player2, BLUE);
		break;
	case 3:
		DrawRectangleRec(Player2, MAGENTA);
		break;
	default:
		break;
	}
	if (!ENElong && !ENEshort)
	{
		DrawTexture(enemy, Player2.x - 35, Player2.y, WHITE);
	}
	else if (ENElong)
	{
		DrawTexture(enemyLONG, Player2.x - 35, Player2.y, WHITE);
	}
	else if (ENEshort)
	{
		DrawTexture(enemySHORT, Player2.x - 35, Player2.y, WHITE);
	}

	DrawRectangleRec(Goal1, SKYBLUE);
	DrawRectangleRec(Goal2, SKYBLUE);
	DrawText(FormatText(" %i", contadorP1), 5, 5, 20, RED);
	DrawText(FormatText(" %i", contadorP2), screenWidth - 25, 5, 20, RED);
	DrawCircleV(ballPosition, radio, colorBola);

	EndDrawing();
}

void drawMenu()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);

	DrawTexture(title, screenWidth / 2 - 80, 0, WHITE);

	DrawText("Elija su color", 210, screenHeight / 2, 60, WHITE);
	DrawText("Para jugar contra otra persona presione Enter", 40, 360, 30, WHITE);
	DrawText("Para Jugar contra la maquina presione Q", 90, 400, 30, WHITE);
	DrawText("A             D", 68, 300, 40, WHITE);
	DrawText("Izq             Der", 435, 300, 40, WHITE);
	EndDrawing();

	if (IsKeyPressed(KEY_A))
	{
		if (color1 > 0)
		{
			color1--;
		}
	}
	if (IsKeyPressed(KEY_D))
	{
		if (color1 < 3)
		{
			color1++;
		}
	}
	if (IsKeyPressed(KEY_LEFT))
	{
		if (color2 > 0)
		{
			color2--;
		}
	}
	if (IsKeyPressed(KEY_RIGHT))
	{
		if (color2 < 3)
		{
			color2++;
		}
	}
	if (IsKeyPressed(KEY_ENTER))
	{
		UnloadTexture(title);
		game = true;
	}
	if (IsKeyPressed(KEY_Q))
	{
		IA = true;
		game = true;
		UnloadTexture(title);
	}
	switch (color1)
	{
	case 0:
		DrawRectangle(100, 300, 200, 40, RED);
		break;
	case 1:
		DrawRectangle(100, 300, 200, 40, SKYBLUE);
		break;
	case 2:
		DrawRectangle(100, 300, 200, 40, GREEN);
		break;
	case 3:
		DrawRectangle(100, 300, 200, 40, YELLOW);
		break;
	default:
		break;
	}
	switch (color2)
	{
	case 0:
		DrawRectangle(500, 300, 200, 40, LIGHTGRAY);
		break;
	case 1:
		DrawRectangle(500, 300, 200, 40, ORANGE);
		break;
	case 2:
		DrawRectangle(500, 300, 200, 40, BLUE);
		break;
	case 3:
		DrawRectangle(500, 300, 200, 40, MAGENTA);
		break;
	default:
		break;
	}
}

void drawGameOver()
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
