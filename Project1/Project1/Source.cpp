#include "raylib.h"

int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;	

	int color1 = 0;
	int color2 = 0;
	int numberPUP = 0;
	int numRand = 0;
	int pUpRand = 0;
	Color colorBola = WHITE;
	bool game = false;
	bool win = false;
	int directionx = 7;
	int directiony = 6;
	const float incremento = 0.3;
	int contadorP1 = 0;
	int contadorP2 = 0;
	const float speed = 7;
	const float speedIA = 5;
	int playerHeight = 100;
	bool IA = false;
	bool ENElong = false;
	bool PLAYlong = false;
	bool ENEshort = false;
	bool PLAYshort = false;
	float P1X = 40;
	float P1Y = screenHeight / 2;
	float P2X = screenWidth - 70;
	float P2Y = screenHeight / 2;
	Rectangle Player1 = { P1X, P1Y, 30, playerHeight };
	Rectangle Goal1 = { 0, 0, 30, screenHeight };
	Rectangle Player2 = { P2X, P2Y, 30, 100 };
	Rectangle Goal2 = { screenWidth - 30, 0, 30, screenHeight };
	float timePlayedHIT = 0.0f;
	float timePlayedPICK = 0.0f;

	InitWindow(screenWidth, screenHeight, "Bad Pong");
	InitAudioDevice();

	Texture2D title = LoadTexture("Assets/Title.png");
	Texture2D player = LoadTexture("Assets/P1.png");
	Texture2D enemy = LoadTexture("Assets/P2.png");
	Texture2D backG = LoadTexture("Assets/fondo.png");
	Texture2D playerLONG = LoadTexture("Assets/P1long.png");
	Texture2D enemyLONG = LoadTexture("Assets/P2long.png");
	Texture2D playerSHORT = LoadTexture("Assets/P1short.png");
	Texture2D enemySHORT = LoadTexture("Assets/P2short.png");

	//Music hitWav = LoadMusicStream("Assets/hit.ogg");
	//Music pickupWav = LoadMusicStream("Assets/pickup.ogg");

	Sound hitWav = LoadSound("Assets/hit.wav");
	Sound pickupWav = LoadSound("Assets/pickup.wav");
	
	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
	Vector2 pUpPosition1 = {(int)0,(int)0 };
	Vector2 pUpPosition2 = { (int)0,(int)0 };
	Vector2 pUpPosition3 = { (int)0,(int)0 };
	int pUpY;
	int radio = 20;
	int radiopUp = 20;

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

		if (game)
		{
			/*UpdateMusicStream(hitWav);
			UpdateMusicStream(pickupWav);*/

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
					directionx += incremento;
				}
				else
				{
					directionx -= incremento;
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
			if (ballPosition.y + radio > screenHeight || ballPosition.y - radio < 0 || CheckCollisionCircleRec(ballPosition, radio, Player1) || CheckCollisionCircleRec(ballPosition, radio, Player2))
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

			if (CheckCollisionCircles(ballPosition, radio,pUpPosition1, radiopUp) && directionx > 0)
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
			else if(CheckCollisionCircles(ballPosition, radio, pUpPosition2, radiopUp) && directionx < 0)
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
			if (CheckCollisionCircles(ballPosition , radio ,pUpPosition3, radiopUp))
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
			//----------------------------------------------------------------------------------

			// Draw
			//----------------------------------------------------------------------------------

			BeginDrawing();
			ClearBackground(BLACK);

			DrawTexture(backG, 0, 0, WHITE);

			if (numberPUP < 1)
			{
				if (numRand == 200)
				{
					if (pUpRand == 0)
					{
						pUpY = GetRandomValue(40, screenHeight-40);
						pUpRand = GetRandomValue(1, 3);
					}
					switch (pUpRand)
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
				DrawRectangleRec(Player1, RED);
				break;
			case 1:
				DrawRectangleRec(Player1, SKYBLUE);
				break;
			case 2:
				DrawRectangleRec(Player1, GREEN);
				break;
			case 3:
				DrawRectangleRec(Player1, YELLOW);
				break;
			default:
				break;
			}
			if (!PLAYlong && !PLAYshort)
			{
				DrawTexture(player, Player1.x - 35, Player1.y, WHITE);
			}
			else if(PLAYlong)
			{
				DrawTexture(playerLONG, Player1.x - 35, Player1.y, WHITE);
			}
			else if (PLAYshort)
			{
				DrawTexture(playerSHORT, Player1.x - 35, Player1.y, WHITE);
			}
			switch (color2)
			{
			case 0:
				DrawRectangleRec(Player2, LIGHTGRAY);
				break;
			case 1:
				DrawRectangleRec(Player2, ORANGE);
				break;
			case 2:
				DrawRectangleRec(Player2, BLUE);
				break;
			case 3:
				DrawRectangleRec(Player2, MAGENTA);
				break;
			default:
				break;
			}
			if (!ENElong && !ENEshort)
			{
				DrawTexture(enemy, Player2.x - 35, Player2.y, WHITE);
			}
			else if (ENElong)
			{
				DrawTexture(enemyLONG, Player2.x - 35, Player2.y, WHITE);
			}
			else if (ENEshort)
			{
				DrawTexture(enemySHORT, Player2.x - 35, Player2.y, WHITE);
			}

			DrawRectangleRec(Goal1, SKYBLUE);
			DrawRectangleRec(Goal2, SKYBLUE);
			DrawText(FormatText(" %i", contadorP1), 5, 5, 20, RED);
			DrawText(FormatText(" %i", contadorP2), screenWidth - 25, 5, 20, RED);
			DrawCircleV(ballPosition, radio, colorBola);

			EndDrawing();
		}
		else if (!game && (contadorP1 < 5 && contadorP2 < 5))
		{
			BeginDrawing();
			ClearBackground(DARKGRAY);

			DrawTexture(title, screenWidth/2 - 80 , 0, WHITE);

			//DrawText("Bienvenido a Bad Pong", 70, screenHeight / 4, 60, WHITE);
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
				DrawRectangle(500, 300, 200, 40, LIGHTGRAY);
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
		if (!game && (contadorP1 == 5 || contadorP2 == 5))
		{
			BeginDrawing();
			ClearBackground(BLACK);
			if (contadorP1 == 5)
			{
				DrawText("Felicidades Jugador 1!", 100, screenHeight / 4, 50, WHITE);
			}
			if (contadorP2 == 5)
			{
				DrawText("Felicidades Jugador 2!", 100, screenHeight / 4, 50, WHITE);
			}
			DrawText(FormatText(" %i", contadorP1), 260, 300, 30, WHITE);
			DrawText(FormatText("Puntaje J1:"), 100, 300, 30, WHITE);

			DrawText(FormatText(" %i", contadorP2), 570, 300, 30, WHITE);
			DrawText(FormatText("Puntaje J2:"), 400, 300, 30, WHITE);

			DrawText("Para jugar otra vez presione Enter", 100, 350, 35, WHITE);
			if (IsKeyPressed(KEY_ENTER))
			{
				game = true;
				contadorP1 = 0;
				contadorP2 = 0;
			}
			DrawText("Para volver al menu presione Q", 100, 390, 35, WHITE);
			if (IsKeyPressed(KEY_Q))
			{
				contadorP1 = 0;
				contadorP2 = 0;
				LoadTexture("Assets/Title.png");
			}

			EndDrawing();
		}
		//----------------------------------------------------------------------------------
	}
	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseAudioDevice();

	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
