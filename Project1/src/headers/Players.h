#pragma once
#include"raylib.h"

namespace Carceglia
{
extern int color1;
extern int color2;
extern int playerHeight;
extern bool enemyLong;
extern bool playLong;
extern bool enemyShort;
extern bool playShort;
extern float P1X;
extern float P1Y;
extern float P2X;
extern float P2Y;
extern bool movingUp;
extern Rectangle player1;
extern Rectangle player2;
extern Texture2D title;
extern Texture2D player;
extern Texture2D enemy;
extern Texture2D backG;
extern Texture2D playerLONG;
extern Texture2D enemyLONG;
extern Texture2D playerSHORT;
extern Texture2D enemySHORT;

void initializePlayers();
void loadPlayerTextures();
void playerMovement();
}
