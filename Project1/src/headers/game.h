#pragma once
#include "raylib.h"

namespace Carceglia
{
	extern const int screenWidth;
	extern const int screenHeight;
	extern int numberPUP;
	extern int numRand;
	extern int powUpRand;
	extern bool game;
	extern bool win;
	extern const float incremento;
	extern int contadorP1;
	extern int contadorP2;
	extern const float speed;
	extern const float speedIA;
	extern bool IA;
	extern Rectangle goal1;
	extern Rectangle goal2;
	extern int radiopUp;
	extern Vector2 pUpPosition1;
	extern Vector2 pUpPosition2;
	extern Vector2 pUpPosition3;
	extern int pUpY;
	extern Sound hitWav;
	extern Sound pickupWav;

	void playGame();
}

