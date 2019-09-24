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
			if (powUpRand == 0)
			{
				pUpY = GetRandomValue(40, screenHeight - 40);
				powUpRand = GetRandomValue(1, 3);
			}
			switch (powUpRand)
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
		DrawRectangleRec(player1, RED);
		break;
	case 1:
		DrawRectangleRec(player1, SKYBLUE);
		break;
	case 2:
		DrawRectangleRec(player1, GREEN);
		break;
	case 3:
		DrawRectangleRec(player1, YELLOW);
		break;
	default:
		break;
	}
	if (!playLong && !playShort)
	{
		DrawTexture(player, player1.x - 35, player1.y, WHITE);
	}
	else if (playLong)
	{
		DrawTexture(playerLONG, player1.x - 35, player1.y, WHITE);
	}
	else if (playShort)
	{
		DrawTexture(playerSHORT, player1.x - 35, player1.y, WHITE);
	}
	switch (color2)
	{
	case 0:
		DrawRectangleRec(player2, DARKGREEN);
		break;
	case 1:
		DrawRectangleRec(player2, ORANGE);
		break;
	case 2:
		DrawRectangleRec(player2, BLUE);
		break;
	case 3:
		DrawRectangleRec(player2, MAGENTA);
		break;
	default:
		break;
	}
	if (!enemyLong && !enemyShort)
	{
		DrawTexture(enemy, player2.x - 35, player2.y, WHITE);
	}
	else if (enemyLong)
	{
		DrawTexture(enemyLONG, player2.x - 35, player2.y, WHITE);
	}
	else if (enemyShort)
	{
		DrawTexture(enemySHORT, player2.x - 35, player2.y, WHITE);
	}

	DrawRectangleRec(goal1, SKYBLUE);
	DrawRectangleRec(goal2, SKYBLUE);
	DrawText(FormatText(" %i", contadorP1), 5, 5, 20, RED);
	DrawText(FormatText(" %i", contadorP2), screenWidth - 25, 5, 20, RED);
	DrawCircleV(ballPosition, radio, colorBola);

	EndDrawing();
}

