#include "raylib.h"
#include "game.h"
#include "Players.h"

namespace Carceglia
{
	bool Initialize = false;
	Texture2D instructions;

	void loadMenu()
	{
		if (!Initialize)
		{
			title = LoadTexture("Assets/Title.png");
			instructions = LoadTexture("Assets/pUPS.png");
			Initialize = true;
		}

		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawTexture(title, screenWidth / 2 - 80, 0, WHITE);
		DrawTexture(instructions, 20, 0, WHITE);

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
			DrawRectangle(500, 300, 200, 40, DARKGREEN);
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
}
