#include "raylib.h"
#include "pelota.h"
#include "Players.h"
#include "Dibujo.h"

bool Init = false;
const int screenWidth = 800;
const int screenHeight = 450;
int numberPUP = 0;
int numRand = 0;
int pUpRand = 0;
bool game = false;
bool win = false;
const float incremento = 0.3;
int contadorP1 = 0;
int contadorP2 = 0;
const float speed = 7;
const float speedIA = 5;
bool IA = false;
int radiopUp = 20;
Vector2 pUpPosition1 = { (int)0,(int)0 };
Vector2 pUpPosition2 = { (int)0,(int)0 };
Vector2 pUpPosition3 = { (int)0,(int)0 };
int pUpY;
Sound hitWav;
Sound pickupWav;
Rectangle Goal1;
Rectangle Goal2;

void initializeGoal()
{
	Rectangle Goal1 = { 0, 0, 30, screenHeight };
	Rectangle Goal2 = { screenWidth - 30, 0, 30, screenHeight };
}

void loadSound()
{
	Sound hitWav = LoadSound("Assets/hit.wav");
	Sound pickupWav = LoadSound("Assets/pickup.wav");
}

void powerupCollision()
{

	if (CheckCollisionCircleRec(ballPosition, radio, Goal1))
	{
		Player1.height = playerHeight;
		Player2.height = playerHeight;
		radio = radiopUp;
		contadorP2++;
		ballPosition.x = screenWidth / 2;
		ballPosition.y = screenHeight / 2;
		PLAYlong = false;
		ENElong = false;
		PLAYshort = false;
		ENEshort = false;
		colorBola = WHITE;
	}
	if (CheckCollisionCircleRec(ballPosition, radio, Goal2))
	{
		Player1.height = playerHeight;
		Player2.height = playerHeight;
		radio = radiopUp;
		contadorP1++;
		PLAYlong = false;
		ENElong = false;
		PLAYshort = false;
		ENEshort = false;
		ballPosition.x = screenWidth / 2;
		ballPosition.y = screenHeight / 2;
		colorBola = WHITE;
	}
	if (contadorP1 == 5 || contadorP2 == 5)
	{
		game = false;
	}

	if (CheckCollisionCircles(ballPosition, radio, pUpPosition1, radiopUp) && directionx > 0)
	{
		Player1.height = 200;
		PLAYlong = true;
		PLAYshort = false;
		pUpPosition1.x = 0;
		pUpPosition1.y = 0;
		numRand = 0;
		pUpRand = 0;
		if (!IsSoundPlaying(pickupWav))
		{
			PlaySound(pickupWav);
		}

	}
	else if (CheckCollisionCircles(ballPosition, radio, pUpPosition1, radiopUp) && directionx < 0)
	{
		Player2.height = 200;
		ENElong = true;
		ENEshort = false;
		pUpPosition1.x = 0;
		pUpPosition1.y = 0;
		numRand = 0;
		pUpRand = 0;

		if (!IsSoundPlaying(pickupWav))
		{
			PlaySound(pickupWav);
		}
	}
	if (CheckCollisionCircles(ballPosition, radio, pUpPosition2, radiopUp && directionx > 0))
	{
		Player2.height = 50;
		ENEshort = true;
		ENElong = false;
		pUpPosition2.x = 0;
		pUpPosition2.y = 0;
		numRand = 0;
		pUpRand = 0;
		if (!IsSoundPlaying(pickupWav))
		{
			PlaySound(pickupWav);
		}

	}
	else if (CheckCollisionCircles(ballPosition, radio, pUpPosition2, radiopUp) && directionx < 0)
	{
		Player1.height = 50;
		PLAYshort = true;
		PLAYlong = false;
		pUpPosition2.x = 0;
		pUpPosition2.y = 0;
		numRand = 0;
		pUpRand = 0;

		if (!IsSoundPlaying(pickupWav))
		{
			PlaySound(pickupWav);
		}

	}
	if (CheckCollisionCircles(ballPosition, radio, pUpPosition3, radiopUp))
	{
		radio = 40;
		pUpPosition3.x = 0;
		pUpPosition3.y = 0;
		numRand = 0;
		pUpRand = 0;
		if (!IsSoundPlaying(pickupWav))
		{
			PlaySound(pickupWav);
		}

	}
}

void playGame()
{
	if (!Init)
	{
		loadPlayerTextures();
		initializePlayers();
		initializeGoal();
		initializeBall();
		loadSound();
		Init = true;
	}

	ballMovement();
	powerupCollision();
	playerMovement();
	drawGame();
}

void gameMenu()
{
	drawMenu();
}

void gameOver()
{
	drawGameOver();
}