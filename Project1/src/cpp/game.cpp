#include "raylib.h"
#include "pelota.h"
#include "Players.h"
#include "Dibujo.h"

namespace Carceglia
{
	bool init = false;
	extern const int screenWidth = 800;
	extern const int screenHeight = 450;
	int numberPUP = 0;
	int numRand = 0;
	int powUpRand = 0;
	bool game = false;
	bool win = false;
	extern const float incremento = 0.3;
	int contadorP1 = 0;
	int contadorP2 = 0;
	extern const float speed = 400.0f;
	extern const float speedIA = 390.0f;
	bool IA = false;
	int radiopUp = 20;
	Vector2 pUpPosition1 = { (int)0,(int)0 };
	Vector2 pUpPosition2 = { (int)0,(int)0 };
	Vector2 pUpPosition3 = { (int)0,(int)0 };
	int pUpY;
	Sound hitWav;
	Sound pickupWav;
	Rectangle goal1;
	Rectangle goal2;

	void initializeGoal()
	{
		goal1 = { 0, 0, 30, screenHeight };
		goal2 = { screenWidth - 30, 0, 30, screenHeight };
	}

	void loadSound()
	{
		hitWav = LoadSound("Assets/hit.wav");
		pickupWav = LoadSound("Assets/pickup.wav");
	}

	void checkPowUpCollision()
	{
		if (CheckCollisionCircleRec(ballPosition, radio, goal1))
		{
			player1.height = playerHeight;
			player2.height = playerHeight;
			radio = radiopUp;
			contadorP2++;
			ballPosition.x = screenWidth / 2;
			ballPosition.y = screenHeight / 2;
			playLong = false;
			enemyLong = false;
			playShort = false;
			enemyShort = false;
			colorBola = BLACK;
		}
		if (CheckCollisionCircleRec(ballPosition, radio, goal2))
		{
			player1.height = playerHeight;
			player2.height = playerHeight;
			radio = radiopUp;
			contadorP1++;
			playLong = false;
			enemyLong = false;
			playShort = false;
			enemyShort = false;
			ballPosition.x = screenWidth / 2;
			ballPosition.y = screenHeight / 2;
			colorBola = BLACK;
		}

		if (CheckCollisionCircles(ballPosition, radio, pUpPosition1, radiopUp) && directionx > 0)
		{
			player1.height = 200;
			playLong = true;
			playShort = false;
			pUpPosition1.x = 0;
			pUpPosition1.y = 0;
			numRand = 0;
			powUpRand = 0;
			if (!IsSoundPlaying(pickupWav))
			{
				PlaySound(pickupWav);
			}

		}
		else if (CheckCollisionCircles(ballPosition, radio, pUpPosition1, radiopUp) && directionx < 0)
		{
			player2.height = 200;
			enemyLong = true;
			enemyShort = false;
			pUpPosition1.x = 0;
			pUpPosition1.y = 0;
			numRand = 0;
			powUpRand = 0;

			if (!IsSoundPlaying(pickupWav))
			{
				PlaySound(pickupWav);
			}
		}
		if (CheckCollisionCircles(ballPosition, radio, pUpPosition2, radiopUp && directionx > 0))
		{
			player2.height = 50;
			enemyShort = true;
			enemyLong = false;
			pUpPosition2.x = 0;
			pUpPosition2.y = 0;
			numRand = 0;
			powUpRand = 0;
			if (!IsSoundPlaying(pickupWav))
			{
				PlaySound(pickupWav);
			}

		}
		else if (CheckCollisionCircles(ballPosition, radio, pUpPosition2, radiopUp) && directionx < 0)
		{
			player1.height = 50;
			playShort = true;
			playLong = false;
			pUpPosition2.x = 0;
			pUpPosition2.y = 0;
			numRand = 0;
			powUpRand = 0;

			if (!IsSoundPlaying(pickupWav))
			{
				PlaySound(pickupWav);
			}

		}
		if (CheckCollisionCircles(ballPosition, radio, pUpPosition3, radiopUp))
		{
			radio = 10;
			pUpPosition3.x = -10;
			pUpPosition3.y = -10;
			numRand = 0;
			powUpRand = 0;

			if (ballPosition.y - radio < 0)
			{
				ballPosition.y += radio;
			}
			if (ballPosition.y + radio > screenHeight)
			{
				ballPosition.y -= radio;
			}

			if (!IsSoundPlaying(pickupWav))
			{
				PlaySound(pickupWav);
			}

		}
	}

	void playGame()
	{
		if (!init)
		{
			loadPlayerTextures();
			loadSound();
			initializeGoal();
			initializeBall();
			initializePlayers();
			init = true;
		}

		updateBallMovement();
		playerMovement();
		checkPowUpCollision();
		drawGame();

		if (contadorP1 == 5 || contadorP2 == 5)
		{
			init = false;
			game = false;
		}
	}
}