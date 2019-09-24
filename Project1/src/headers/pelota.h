#pragma once

namespace Carceglia
{
extern Color colorBola;
extern float directionx;
extern float directiony;
extern int radio;
extern Vector2 ballPosition;

void initializeBall();
void updateBallMovement();
}
