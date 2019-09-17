#include "raylib.h"
#include "game.h"
#include "pelota.h"

int color1 = 0;
int color2 = 0;
int playerHeight = 100;
bool ENElong = false;
bool PLAYlong = false;
bool ENEshort = false;
bool PLAYshort = false;

Texture2D title;
Texture2D player;
Texture2D enemy;
Texture2D backG;
Texture2D playerLONG;
Texture2D enemyLONG;
Texture2D playerSHORT;
Texture2D enemySHORT;

Rectangle Player1;
Rectangle Player2;

void initializePlayers()
{
	float P1Y = screenHeight / 2;
	float P2X = screenWidth - 70;
	float P2Y = screenHeight / 2;
	float P1X = 40;
	Player1.x = P1X;
	Player1.y = P1Y;
	Player1.width = 30;
	Player1.height = playerHeight;

	Player2.x = P2X;
	Player2.y = P2Y;
	Player2.width = 30;
	Player2.height = 100;
}

void loadPlayerTextures()
{
	player = LoadTexture("Assets/P1.png");
	enemy = LoadTexture("Assets/P2.png");
	backG = LoadTexture("Assets/fondo.png");
	playerLONG = LoadTexture("Assets/P1long.png");
	enemyLONG = LoadTexture("Assets/P2long.png");
	playerSHORT = LoadTexture("Assets/P1short.png");
	enemySHORT = LoadTexture("Assets/P2short.png");
}

void playerMovement()
{
	if (IsKeyDown(KEY_W))
	{
		if (Player1.y > 0)
		{
			Player1.y -= speed;
		}
	}
	if (IsKeyDown(KEY_S))
	{
		if (Player1.y + Player1.height < screenHeight)
		{
			Player1.y += speed;
		}
	}
	if (IA)
	{
		if (Player2.y > ballPosition.y && Player2.y > 0)
		{
			Player2.y -= speedIA;
		}
		if (Player2.y < ballPosition.y && Player2.y + Player2.height < screenHeight)
		{
			Player2.y += speedIA;
		}
	}
	if (IsKeyDown(KEY_UP) && !IA)
	{
		if (Player2.y > 0)
		{
			Player2.y -= speed;
		}
	}
	if (IsKeyDown(KEY_DOWN) && !IA)
	{
		if (Player2.y + Player2.height < screenHeight)
		{
			Player2.y += speed;
		}
	}
}