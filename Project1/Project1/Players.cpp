#include "raylib.h"
#include "game.h"
#include "pelota.h"

Rectangle Player1;
Rectangle Player2;
int color1 = 0;
int color2 = 0;
int playerHeight = 100;
bool ENElong = false;
bool PLAYlong = false;
bool ENEshort = false;
bool PLAYshort = false;
float P1X = 40;

void initializePlayers()
{
	float P1Y = screenHeight / 2;
	float P2X = screenWidth - 70;
	float P2Y = screenHeight / 2;
	Rectangle Player1 = { P1X, P1Y, 30, playerHeight };
	Rectangle Player2 = { P2X, P2Y, 30, 100 };
}

void loadPlayerTextures()
{
	Texture2D title = LoadTexture("Assets/Title.png");
	Texture2D player = LoadTexture("Assets/P1.png");
	Texture2D enemy = LoadTexture("Assets/P2.png");
	Texture2D backG = LoadTexture("Assets/fondo.png");
	Texture2D playerLONG = LoadTexture("Assets/P1long.png");
	Texture2D enemyLONG = LoadTexture("Assets/P2long.png");
	Texture2D playerSHORT = LoadTexture("Assets/P1short.png");
	Texture2D enemySHORT = LoadTexture("Assets/P2short.png");
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