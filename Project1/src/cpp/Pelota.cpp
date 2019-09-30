

#include "raylib.h"

#include "game.h"
#include "Players.h"


namespace Carceglia
{
	float directionx = 450.0f;
	float directiony = 400.0f;
	int radio = 20;
	Vector2 ballPosition;
	Color colorBola;

	void initializeBall()
	{
		Color colorBola = BLACK;
		Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
	}

	void updateBallMovement()
	{
		ballPosition.x += directionx * GetFrameTime();
		ballPosition.y += directiony * GetFrameTime();

		if (ballPosition.x + radio > screenWidth || ballPosition.x - radio < 0
			|| CheckCollisionCircleRec(ballPosition, radio, player1)
			|| CheckCollisionCircleRec(ballPosition, radio, player2))
		{
			if (directionx > 0)
			{
				switch (color2)
				{
				case 0:
					colorBola = DARKGREEN;
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

			if (CheckCollisionCircleRec(ballPosition, radio, player1))
			{
				ballPosition.x += radio / 2;
			}
			if (CheckCollisionCircleRec(ballPosition, radio, player2))
			{
				ballPosition.x -= radio / 2;
			}
		}

		if (ballPosition.y + radio > screenHeight || ballPosition.y - radio < 0)
		{
			directiony *= -1;
		}

		if (CheckCollisionCircleRec(ballPosition, radio, player1)
			|| CheckCollisionCircleRec(ballPosition, radio, player2))
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

			if (movingUp)
			{
				directiony *= -1;
			}

			if (CheckCollisionCircleRec(ballPosition, radio, player1))
			{
				ballPosition.y += radio / 2;
			}
			if (CheckCollisionCircleRec(ballPosition, radio, player2))
			{
				ballPosition.y -= radio / 2;
			}
		}
	}
}