#include "game.h"
#include "Players.h"
#include "raylib.h"

int directionx = 7;
int directiony = 6;
int radio = 20;
Vector2 ballPosition;
Color colorBola;

void initializeBall()
{
	Color colorBola = WHITE;
	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
}

void ballMovement()
{
	ballPosition.x += directionx;
	ballPosition.y += directiony;

	if (ballPosition.x + radio > screenWidth || ballPosition.x - radio < 0
		|| CheckCollisionCircleRec(ballPosition, radio, Player1)
		|| CheckCollisionCircleRec(ballPosition, radio, Player2))
	{
		if (directionx > 0)
		{
			switch (color2)
			{
			case 0:
				colorBola = LIGHTGRAY;
				break;
			case 1:
				colorBola = ORANGE;
				break;
			case 2:
				colorBola = BLUE;
				break;
			case 3:
				colorBola = MAGENTA;
				break;
			default:
				break;
			}
		}
		else
		{
			switch (color1)
			{
			case 0:
				colorBola = RED;
				break;
			case 1:
				colorBola = SKYBLUE;
				break;
			case 2:
				colorBola = GREEN;
				break;
			case 3:
				colorBola = YELLOW;
				break;
			default:
				break;
			}
		}

		if (!IsSoundPlaying(hitWav))
		{
			PlaySound(hitWav);
		}

		directionx *= -1;

		if (CheckCollisionCircleRec(ballPosition, radio, Player1))
		{
			ballPosition.x += radio / 2;
		}
		if (CheckCollisionCircleRec(ballPosition, radio, Player2))
		{
			ballPosition.x -= radio / 2;
		}
	}
	if (ballPosition.y + radio > screenHeight || ballPosition.y - radio < 0 
		|| CheckCollisionCircleRec(ballPosition, radio, Player1) 
		|| CheckCollisionCircleRec(ballPosition, radio, Player2))
	{
		if (directiony > 0)
		{
			directiony += incremento;
		}
		else
		{
			directiony -= incremento;
		}

		if (!IsSoundPlaying(hitWav))
		{
			PlaySound(hitWav);
		}

		directiony *= -1;

		if (CheckCollisionCircleRec(ballPosition, radio, Player1))
		{
			ballPosition.y += radio / 2;
		}
		if (CheckCollisionCircleRec(ballPosition, radio, Player2))
		{
			ballPosition.y -= radio / 2;
		}
	}
}