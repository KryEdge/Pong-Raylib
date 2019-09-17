#pragma once
#include"raylib.h"

extern int color1;
extern int color2;
extern int playerHeight;
extern bool ENElong;
extern bool PLAYlong;
extern bool ENEshort;
extern bool PLAYshort;
extern float P1X = 40;
extern float P1Y;
extern float P2X;
extern float P2Y;
extern Rectangle Player1;
extern Rectangle Player2;
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