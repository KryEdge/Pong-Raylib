#include "Players.h"

#include "raylib.h"

#include "game.h"
#include "pelota.h"

namespace Carceglia
{
	int color1 = 0;
	int color2 = 0;
	int playerHeight = 100;
	bool enemyLong = false;
	bool playLong = false;
	bool enemyShort = false;
	bool playShort = false;
	bool movingUp = false;

	Texture2D title;
	Texture2D player;
	Texture2D enemy;
	Texture2D backG;
	Texture2D playerLONG;
	Texture2D enemyLONG;
	Texture2D playerSHORT;
	Texture2D enemySHORT;

	Rectangle player1;
	Rectangle player2;

	void initializePlayers()
	{
		float p1Y = screenHeight / 2;
		float p2X = screenWidth - 70;
		float p2Y = screenHeight / 2;
		float p1X = 40;
		player1.x = p1X;
		player1.y = p1Y;
		player1.width = 30;
		player1.height = playerHeight;

		player2.x = p2X;
		player2.y = p2Y;
		player2.width = 30;
		player2.height = 100;
	}

	void loadPlayerTextures()
	{
		player = LoadTexture("Assets/P1.png");
		enemy = LoadTexture("Assets/P2.png");
		backG = LoadTexture("Assets/fondo.jpg");
		playerLONG = LoadTexture("Assets/P1long.png");
		enemyLONG = LoadTexture("Assets/P2long.png");
		playerSHORT = LoadTexture("Assets/P1short.png");
		enemySHORT = LoadTexture("Assets/P2short.png");
	}

	void playerMovement()
	{
		if (IsKeyDown(KEY_W))
		{
			if (player1.y > 0)
			{
				player1.y -= speed * GetFrameTime();
			}
			movingUp = true;
		}
		if (IsKeyDown(KEY_S))
		{
			if (player1.y + player1.height < screenHeight)
			{
				player1.y += speed * GetFrameTime();
			}
			movingUp = false;
		}
		if (IA)
		{
			if (player2.y > ballPosition.y && player2.y > 0)
			{
				player2.y -= speedIA * GetFrameTime();
			}
			if (player2.y < ballPosition.y && player2.y + player2.height < screenHeight)
			{
				player2.y += speedIA * GetFrameTime();
			}
		}
		if (IsKeyDown(KEY_UP) && !IA)
		{
			if (player2.y > 0)
			{
				player2.y -= speed * GetFrameTime();
			}
		}
		if (IsKeyDown(KEY_DOWN) && !IA)
		{
			if (player2.y + player2.height < screenHeight)
			{
				player2.y += speed * GetFrameTime();
			}
		}
	}
}
