#include "game.h"
#include "raylib.h"
#include "pelota.h"
#include "Players.h"

void executeGame()
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

